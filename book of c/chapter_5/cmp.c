#include <string.h>
#include <stdio.h>

int cmp(char*, char*,int);

 main(){

	 char* x = "labasB";
	 char* y = "labasC";

         int c = cmp(x,y,7);

	 printf("c: %d\n",c);

};


int cmp(char* s, char* t, int n){
    
	while(*s++ == *t++)
         if(--n == 0)
	  return 0;

        return *(s-1) - *(t-1); 

}	
