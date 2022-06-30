#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <math.h>
#include <string.h>


#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 15 
#define BUFSIZE 100

#define VAR_ADD '1'
#define VAR_PRINT '2'
#define VAR_REM '3'
#define VAR_GET '4'

char buf[BUFSIZE];
int bufp = 0;
/* buffer for ungetch */
/* next free position in buf */
int sp = 0;
double val[MAXVAL];

char variables[200];
// g 2\n h 4\n


char* reserved = "\n+*-/%cspdESPl:\',;\0";

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

void print_stack();
void duplicate(int n);
void swap_two();
void clear_stack();

void add_variable(char* s);
void remove_variable(char c);
int get_variable(char c, double* f,int silent );
int get_index(char c, char* s);

void delete_line(char c, char* s1);
void copy_line(char* s0, char* s1);

void ungets(char *s);

 main(){
   int type;
   double op2;
   char s[MAXOP];
    while ((type = getop(s)) != EOF) {
     switch (type){
      case NUMBER:
       push(atof(s));
        break;
      case '+':
       push(pop() + pop());
        break;
      case '*':
       push(pop() * pop());
        break;
      case '-':
       op2 = pop();
       push(pop() - op2);
        break;
      case '/':
       op2 = pop();
        if (op2 != 0.0)
         push(pop() / op2);
        else
        printf("error: zero divisor\n");
	break;
      case '%':
       op2 = pop();
        if (op2 != 0.0)
         push((int)pop() % (int)op2);
        else
        printf("error: zero divisor\n");
         break;
      case 'c':
	clear_stack();
	getch();
	break;
      case 's':
	 swap_two();
	 getch();
	 break;
      case 'p':
	 print_stack();
	 getch();
	 break;
      case 'd':
	 duplicate(1);
	 getch();
	 break;
      case 'E':
         push(exp(pop()));
	 break;
      case 'S':
         push(sin(pop()));
	 break;
      case 'P':
         push(pow(pop(),pop()));
         break;
      case VAR_ADD: 
         add_variable(s);	
         break;
      case VAR_PRINT:
          if( get_variable(s[0],&op2,0)==0 )
           if(s[0] == 'l')
	    printf("last = %f\n",op2);
	     else
	      printf("%c = %f\n",s[0],op2);
	  getch();
	  
	  break;
      case VAR_REM:
	  remove_variable(s[0]);
	  getch();
	   break;
      
      case ':':
	 ungets(s);
	 break;
      case ',':
	 push(val[sp-1]);
	 break;
     case ';':
      case '\n':
        printf("\t%.8g\n",val[sp-1]);
         break;
 default:

  if( get_variable(s[0],&op2,0)==0 )
    push(op2);
     else
      printf("error: unknown command %s\n", s);
 break;
     }
   }
  return 0;
 }




/* maximum depth of val stack */
/* next free stack position */
/* value stack */
/* push: push f onto value stack */
void push(double f){
 if (sp < MAXVAL)
 val[sp++] = f;
 else
  printf("error: stack full, can't push %g\n", f);
 }
 /* pop: pop and return top value from stack */
 double pop(void){
  if (sp > 0)
   return val[--sp];
  else {
   printf("error: stack empty\n");
   return 0.0;
  }
 }






/* getop: get next character or numeric operand */
int getop(char s[])
{
int i=0, c;
while ((s[0] = c = getch()) == ' ' || c == '\t')
;//skip spaces and tabs

if(c=='v'){
  while( (s[i++] = getch()) != '\n' );
  s[i-1] = '\0';
  return VAR_ADD;
};

if(c=='g'){ 
 s[0] = getch();
 s[1] = '\0';
 return VAR_PRINT;
};

if(c=='r'){
 s[0] = getch();
 return VAR_REM; 
};



//int x = get_variable(c,&c,0);
// Kodel luzta nuo sito call? stack smashing detected
// valgrind --leak-check=full ./a.out



 
  
  
  


 
if (!isdigit(c) && c != '.' && c!= '-'){

if(c=='\n'){
  
}



s[1] = '\0';
return c;
};

if (c=='-'){
c = getch();
if( isdigit(c) || c=='.' ){
  i=1;
  s[i] = c;
}else {ungetch(c); s[1] ='\0'; return '-';}
};


if (isdigit(c))
/* collect integer part */
while (isdigit(s[++i] = c = getch()))
;
if (c == '.')
/* collect fraction part */
while (isdigit(s[++i] = c = getch()))
;
s[i] = '\0';
if (c != EOF)
ungetch(c);
return NUMBER;



}






int getch(void) /* get a (possibly pushed-back) character */
{ int result =  (bufp > 0) ? buf[--bufp] : getchar();
  return (result == '\'') ? EOF : (result == ';') ? '\n' : result;
};

void ungetch(int c)
/* push character back on input */
{
if (bufp >= BUFSIZE)
printf("ungetch: too many characters\n");
else
buf[bufp++] = c;
}

void print_stack(){
  
  if(sp == 0){
     printf("stack is empty!\n");
     return;
   };
  for(int i = sp-1; i >= 0 ; i--)
    printf("%d: %f\n",i,val[i]);
};


void duplicate(int n){

   if( (sp+n) > MAXVAL ){
     printf("cannot duplicate!\n");
     return;
   };

  for(int i = sp - n,target = sp; i < target; i++)
   push(val[i]);

    printf("duplicated\n");
};

void swap_two(){

   if(sp<2){
     printf("did not swap!\n");
     return;
   }
      double temp = val[sp-1];
      val[sp-1] = val[sp-2];
      val[sp-2] = temp;
      printf("swap was OK\n");
      
};

void clear_stack(){
 if(sp==0){
   printf("already clean!\n");
   return;
 };

  sp = 0;
  val[sp] = 0;
   printf("cleared\n");
};

int get_index(char c, char* s){
 
       for(int i = 0; i < strlen(s); i++)
         if( s[i] == c )
          return i;

    return -1;       
}	
void add_variable(char *s){


	if(strlen(s) == 0){
	   printf("variable name cannot be empty!\n");
	   return;
	};
    
	char c  = s[strlen(s)-1];
	s[strlen(s)-1] = '\0';

	for(int i = 0; i < strlen(s); i++)
	  if(!isdigit(s[i]) )
	   if(s[i] != '.'){
	   
	     printf("cannot use letter %c as number!\n",s[i]);
	     return;
	  };
	double  key = atof(s);
	

	
	    
           if(isdigit(c)){printf("cannot use number %d as a var name!\n",c);return;}
	   int n = get_index(c, variables);
	   if(n != -1){
		  printf("%c is already taken!\n",c);
		  return;
	   };

	   
          n = get_index(c,reserved);
	  
	   if(n != -1){
		  printf("%c is reserved char! \n",c);
		  return;
	   };

	   if(isdigit(c)){
		   printf("variable name can't be a digit!\n");
		   return;
	   };


        char record[20];
	record[0] = c;
        sprintf(s," %f",key);
	strcpy(record+1,s);
        int len = strlen(record);
	record[len] = '\n';
	record[len+1] = '\0';

	strcat(variables,record);
	printf("variable %c created!\n",c);
};


int get_variable(char c, double* f, int silent ){
    
       if(c=='*'){
	if(strlen(variables) == 0)
	 printf("no vars!\n");
	  else
	 printf("%s",variables);
         return -1;
       };

       if(c=='l'){ 
          *f = val[sp-1];
          return 0;
       };

       int n = get_index(c,variables);
       if(n == -1 || isdigit(c)){
	if(silent == 0)
	 printf("%c is not a var!\n",c);
         return -1;  
       };

      char temp[20];
      copy_line(temp,variables+n+2);
      
  
       *f = atof(temp);
      return 0; 

};

void remove_variable(char c){
    
     int n = get_index(c,variables);
     if(n == -1){
      printf("%c is not a var!\n",c);
      return;
     }else{  
	     
	     delete_line(c,variables);
             printf("var %c is removed!\n",c);
	  };
};

void copy_line(char* s0, char* s1){

	for(char* i = s1; *(i) != '\n'; i++)
	  *(s0++) = *(i);

	*(s0) = '\0';

};

void delete_line(char c,char* s){

int i, j; 
for(i = 0, j = 0; i<strlen(s); )
  if(s[i] == c)
     while(s[i++] != '\n');   
    else
     s[j++] = s[i++];

   s[j] = '\0';
     
};

void ungets(char *s){

char temp[100];
int x, i = 0;



while( (temp[i++]= getchar()) != '\n')
  ;

x = i;
while(i>0)
  ungetch(temp[--i]);

temp[x-1] = '\0';

 printf("\npushed \"%s\" to buf\n",temp);

};
