#include <stdlib.h>
#include <stdio.h>

main(int c,char** args)
{


  int* m = malloc( sizeof(int) * (c-1) );
  for(int i = 0; i < c-1 ;i++) 
   m[i] = atoi(args[i+1]);




/* horizontal */
  for(int i = 0; i < (c-1); i++){
   for(int j = 0; j < m[i]; j++)
	putchar('*');
  putchar('\n');
  };

/* vertical */
  printf("\n\n");
  int max = 0;
  for(int i = 0; i < (c-1); i++)
     if(m[i] > max)max = m[i];


  char string[99][99];
  int line = 0; 

  do{ int i;
   for(i = 0; i < c-1 ;i++)
    if(--m[i] > -1)
     string[line][i] = '*';
     else string[line][i] = ' ';

   string[line][i] = '\0';
   line++;
  }while(line < max);


  for(int i = line-1; i >= 0; i--) 
	printf("%s\n",string[i]);

    
       

}
