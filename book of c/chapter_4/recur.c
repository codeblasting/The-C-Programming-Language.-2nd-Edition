#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char*,int,int);
void reverse2(char*);

main(){
 
  char x[] = "12345";
  reverse(x,0,strlen(x)-1);
  printf("%s\n",x);
  reverse2(x);
  printf("%s\n",x);

 };

void reverse(char* s,int i,int j)
{

if(i >= strlen(s)/2)return;
reverse(s,i+1,j-1);

int c;
c = s[i];
s[i] = s[j];
s[j] = c;

}

void reverse2(char* str){

int c;
	
	int i = strlen(str)+1;       
	static int k = 0;
        if(k >= i/2)return;
        

	
		 int temp = str[k];
		 str[k] = str[i-2-k];
		 str[i-2-k] = temp;

        
	k++;
        reverse2(str);

	
		
	 
};	
