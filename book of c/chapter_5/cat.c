#include <stdio.h>
#include <string.h>

void strn(char*,char*,int);

 main(){

	 char x[40];
	 x[0] = '\0'; 
	 strn(x,"labas",3);
	 
	 printf("%s\n",x);
	 strn(x+strlen(x)," labas",6);
	 printf("%s\n",x);

 }


void strn(char* dest, char* src,int n){
     
  while(n--)
  *dest++ = *src++;
   *dest = '\0';
  
}

