#include <stdio.h>


int main(){

   int c = 3;

   c = (c>='A' && c<='Z') ? c+32 : c;

   putchar(c);
   putchar(10);


}
