#include <stdlib.h>
#include <stdio.h>


void main(){
 for(int i = 0,x;
  (x = getchar())!=EOF;
   printf("i:%d\n",i+=(x=='a'))
  )	;
}
	
	


