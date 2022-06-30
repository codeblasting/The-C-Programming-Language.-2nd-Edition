#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* chartostr(char x){

	char* c = malloc(2);
	c[0] = x;
	c[1] = '\0';
	return c;

}

int main(){
 
	char t[20];
	char s[40];
	s[0] = '\0';

        
	/*
	scanf("%[^\n]",t);
        
	for(int i = 0; i < strlen(t); i++)
	  switch(t[i]){
             
            case '\t':strcat(s,"\\t");break;
	    case ' ':strcat(s,"\\s");break;
	    default:strncat(s,t+i,1);
         
	  };


	/***************************************/

	scanf("%[^\n]",t);
        for(int i = 0; i < strlen(t); i++){
           
	  if(strncmp(t+i,"\\t",2)==0)
	   strncat(s,"\t",1);
	    else

	  if(strncmp(t+i,"\\s",2)==0)
	   strncat(s," ",1);
	    else
             strncat(s,chartostr(t[i]),1);
	};
           

	printf("%s",s);
}
