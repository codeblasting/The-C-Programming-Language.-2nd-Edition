#include "custom.h"


char* reserved = "\n+*-/%cspdESPl:\',;\0";



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

char *temp;
int x, i = 0;


if(s==0){
temp = malloc(100);
while( (temp[i++] = getchar()) != '\n')
  ;
x = i;
}
else { i = strlen(s);
       temp = s;
     }
    

x = i;
while(i>0)
  ungetch(temp[--i]);

temp[x-1] = '\0';

 printf("\npushed \"%s\" to buf\n",temp);

};



