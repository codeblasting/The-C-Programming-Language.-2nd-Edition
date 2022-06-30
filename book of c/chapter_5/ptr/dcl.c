#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getch.h"

#define MAXTOKEN 100
 enum { NAME, PARENS, BRACKETS };
 
 void dcl(void);
 void dirdcl(void);
 int gettoken(void);
 void get_args();
 int tokentype;
 char token[MAXTOKEN];
 char name[MAXTOKEN];
 char datatype[MAXTOKEN]; 
 char out[1000];
 int error = 0;
 char arg_str[50];

 void get_args(){

  char *p = arg_str;

  do{
  *p=getch();
   }while(*(p++)!=')');

  ungetch(*(p-1));
  *(p-1) = '\0';


};

 void reset_all(){
  

  while(tokentype!= '\n')
   gettoken();

  error = 0;

}

 main(){

  while (tokentype != '\n') {
   
   gettoken();
   strcpy(datatype,token);

   if(strcmp(token,"const") == 0){
    strcat(datatype," ");
    gettoken();
    strcat(datatype,token);
   };
   
    out[0] = '\0';

     dcl();
      if(error){
         reset_all();             
         continue;
      };

      if (tokentype != '\n'){
       printf("syntax error\n");
       reset_all();     
       continue;
       }

    printf("%s: %s %s\n", name, out, datatype);
    printf("args: %s\n",arg_str);
   }

    return 0;
 }


 void dcl(void){

  int ns;
   for (ns = 0; gettoken() == '*'; ) /* count *'s */
    ns++;

  dirdcl();
   if(error)
    return;
  


   while (ns-- > 0)
    strcat(out, " pointer to");
 }


 void dirdcl(void){

  int type;
   if (tokentype == '(') {
     
    dcl();
     if(error)
      return;
    


     if (tokentype != ')'){
      printf("error: missing )\n");
      error = 1;
      return;
     }


   }else if(tokentype == NAME) 
    strcpy(name, token);
   else{
    printf("error: expected name or (dcl)\n");
    error = 1;
    return;
    }
  while ((type=gettoken()) == PARENS || type == BRACKETS)
   if (type == PARENS)
    strcat(out, " function returning");
     else {
     strcat(out, " array");
     strcat(out, token);
     strcat(out, " of");
    }
 }



 int gettoken(void){
  int c, getch(void);
  void ungetch(int);
  char *p = token;
 
  while ((c = getch()) == ' ' || c == '\t')
   ;
   if (c == '(') {
    get_args();
    
    if ((c = getch()) == ')') {
    strcpy(token, "()");
    return tokentype = PARENS;
   } else {
    ungetch(c);
   return tokentype = '(';

  }
  } else if (c == '[') {
for (*p++ = c; (*p++ = getch()) != ']'; )
;
*p = '\0';
return tokentype = BRACKETS;
} else if (isalpha(c)) {
for (*p++ = c; isalnum(c = getch()); )
*p++ = c;
*p = '\0';
ungetch(c);



return tokentype = NAME;
} else
return tokentype = c;
}
