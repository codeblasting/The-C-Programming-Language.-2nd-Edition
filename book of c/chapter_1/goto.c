#include <stdio.h>

main(){

	int x = 1;
	if(x==1)goto p;
	  else goto  q;

p: printf("x=1\n");
   goto z;
q: printf("x=2\n");
z:;

}
