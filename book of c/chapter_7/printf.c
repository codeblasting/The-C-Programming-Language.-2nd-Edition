#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

 char s[50];
 scanf("%[^EOF]s",s);

printf("%.5s\n%s",s,s+5);

printf("\n");
};
  
