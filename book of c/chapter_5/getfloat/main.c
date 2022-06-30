#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "getch.h"
#include <math.h>


/* getint: get next integer from input into *pn */
int getfloat(long double *pn){
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

     
     int i;
     if(c=='.')
       for(i = 0,c = getch(); isdigit(c); c = getch(), i++)
        *pn =  10 * *pn + (c - '0'); 
      *pn/=pow(10,i);
		  
     *pn *= sign;

       if (c != EOF)
       ungetch(c);
        return c;

};

  main(){

	  long double c;
	  int x = getfloat(&c);
	  printf("%Lf\n",c); 


  };
