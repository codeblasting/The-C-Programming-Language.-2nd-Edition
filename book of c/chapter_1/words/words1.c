#include <stdio.h>
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */




main(){
   int c, nw, state, count, m[5];
   state = IN;
   count = nw = 0;
     do {
       c = getchar();
        if (c == ' ' || c == '\n' 
       || c == '\t')
         state = OUT;
          else if (state == OUT) {
           m[nw++] = count;
           count = 1;
           state = IN;
          }else if(state == IN)
           count++;
     }while (c!= EOF);


  for(int i =0; i<5; i++)
   printf("%d\n",m[i]);
}
