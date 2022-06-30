#include <stdio.h>
#define true  1
#define false 0

main(){

	for(int c = getchar(), space = 0; c != EOF; c = getchar()){
	  if( c == ' ' )
	   { if( space )continue;   
	     putchar(c);
             space = true;
           }else { space = false; putchar(c);};	     
	}

}
