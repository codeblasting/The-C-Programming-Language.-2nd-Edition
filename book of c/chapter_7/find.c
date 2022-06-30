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
};

int main(int c, char** args){

  FILE* files[10];
  char c1[400];
  int k = c-2;
   
if(c>2)
  for(int i = 1; i < c-1; i++)
   files[i-1] = fopen(args[i],"r");
    else{ files[0] = stdin; k = 1; }
  
 
  for(int i = 0; i < k; i++){
    int e = 1;
    int n = 0;
     while(fgets(c1,50,files[i])){ 
      n++;
      int r = strindex(c1,args[c-1]);
      if(r!=-1)
       printf("FOUND STRING %s ON LINE %d IN FILE %s\n",args[c-1],n,args[i+1]);
      };
 
   }

       

}
