#include <stdio.h>

main(){
  
	int previous, current, words,count, m[5], c;
	previous = current = words = count = 0;

	do{
		c = getchar();
		if(c == ' ' || c == EOF || c== '\n'){
			previous = current;
			current = 0;
			if(previous == 1){
			  m[words++] = count;
			  count = 0;
			}
		}else { previous = current;
			current = 1;
			count++;
		}
       	}while( c != EOF );


  for(int i = 0; i < 5; i++)
	  printf("%d\n",m[i]);
}
