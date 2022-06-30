#include <stdio.h>
#include <ctype.h>
#include <string.h>

main(int argc, char** argv) /* lower: convert input to lower case*/
{
 char* x = argv[1];
 char c;
  while ((c = getchar()) != EOF)
  if(c!=10)
   if(strcmp(x,"-h") == 0)
    printf("%c\n",c-32);
     else
      printf("%c\n",c+32);
   
   return 0;
}
