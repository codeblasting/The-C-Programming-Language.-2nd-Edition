#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){

FILE* f1 = fopen(argv[1],"r");
FILE* f2 = fopen(argv[2],"r");
char c1[520],c2[520];

int same = 1;

 while(same){
  
 int e1 = fgets(c1,511,f1);
 int e2 = fgets(c2,511,f2);
 
 if( (e1 == e2) && e1 == 0)
  break;

  if(strcmp(c1,c2)!=0){
   same = 0;
   printf("%s\n%s\n",c1,c2);
  }

 }

if(same)
 printf("files are the same!\n");
    
};
