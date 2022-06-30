#include <stdio.h>
#include <stdlib.h>

void itoa(int,char*);
void p(char* s){

  printf("%c\n",*s);
   
if(*s == '\0')return;
 else{ s++;
  p(s);}

};
int main(){

  char x[10];
  itoa(-102,x);
  printf("%s\n",x);


 };


void itoa(int n, char* s){

static int index = 0;

 if (n < 0) {
  *(s) = '-';
    index = 1;
    n = -n;
 };

if (n / 10)
 itoa(n / 10,s);
 *(s+index) = n % 10 + '0';
 *(s+index+1) = '\0';
 index++;
 
};

