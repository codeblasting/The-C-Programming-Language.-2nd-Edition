#include <stdio.h>
#include <stdlib.h>



void decToBase(int n,int base,int digits, char* x)
{ 
   int r,i = digits-1;
   int neg = (n<0) ? 1 : 0;
   
   if(neg){
    x[0] = '-';
    i++;
    n=-n;
   };

   x[i+1] = '\0';
	do{
          r = n%base;
          n = n/base;
          x[i] = (r>=10) ? (r+55 ) : (r+48);	  
	}while(--i);
 
	
       
	return;

}


int main(int argc, char** argv)
{ 
   char* input = malloc(50);
   int n = atoi(argv[1]);
   int base = atoi(argv[2]); 
   decToBase(n,base,4,input);
   
   printf("%s\n",input);  

}
