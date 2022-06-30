#include <stdio.h>
#include <string.h>


int strindex(char s[], char t[]){
int i, j, k;
 for(i = strlen(s)-1; i >= 0; i--){
  for(j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++);

   if (k == strlen(t))
    return i;
 }

  return -1;
}

int main(int c, char** args){


  int n = strindex(args[1],args[2]);
  
  printf("%d\n",n);

};
