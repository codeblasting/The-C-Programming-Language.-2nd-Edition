#include <stdlib.h>
#include <stdio.h>
#define true 1
#define false 0

 main(){

        int IN_WORD = true;
	int c, word, count,m[10];
	word = count = 0;

	
        while( ( c = getchar() ) != EOF ) 
		if( ( c == ' ' || c == '\n') )
		{  if(!IN_WORD)continue; 
		   m[word++] = count; 
	           count = 0;
		   IN_WORD = false;
		   
		 }else { IN_WORD = true; count++;}

       for(int  i = 0; i < word; i++)
	      printf("%d ",m[i]);

      printf("\n"); 
    

};
