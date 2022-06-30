#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "getch.h"


/* getint: get next integer from input into *pn */
int getint(long int *pn){
 int c, sign;
  while (isspace(c = getch()))
  /* skip white space */
  ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
  ungetch(c); /* it is not a number */
   return 0;
  }

  sign = (c == '-') ? -1 : 1;
   if (c == '+' || c == '-')
    c = getch();
    
   if (!isdigit(c) ){
	ungetch(c);
	return 0;
   }
   
    for (*pn = 0; isdigit(c) ; c = getch())
     *pn = 10 * *pn + (c - '0');

     *pn *= sign;
       if (c != EOF)
       ungetch(c);
        return c;

};

  main(){
          printf("%ld\n",-1>>32);return;
	  long int c;
	  int x = getint(&c);
	  printf("%d %d\n",c,x);


  };
