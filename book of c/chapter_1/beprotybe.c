#include <stdio.h>
#include <string.h>
#define COL 3

int get_break(char* str,int from, int until);

main(){
  
  char arg_str[99],
       res_str[99];

  scanf("%[^\n]",arg_str);
  int br = -1;
  int len = strlen(arg_str);
  int until,from;
 
    do{
	 from = br+1;
	 until = ( from + COL-1 < len-1 ) ? (from+COL-1) : (len-1);
	 int x = 0;

         br = get_break(arg_str, from, until);
	 printf("br : %d\n",br);
	 for( int j = br-(COL+1); j <= br; j++){
	  res_str[x+j] = arg_str[j];
          printf("x+j: %d|",br-COL+1);
	  printf("j %d ",j);
	 }

	 x=1; 

	 res_str[br+1] = '0';
         printf("str %s\n", res_str);
        	
    }while( until < len-1 );

  printf("res:\n%s\n",res_str);
    



}

int get_break(char* str,int from, int until){


	while(str[until] != from) 
	  if(str[until--] != '-')
	   return until+1;

	return until;

}
