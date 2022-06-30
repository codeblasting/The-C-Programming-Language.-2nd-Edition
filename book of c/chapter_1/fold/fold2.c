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
  int last_index = 0;
 
	 int x = 0;
    do{
	 from = br+1;
	 until = ( from + COL-1 < len-1 ) ? (from+COL-1) : (len-1);

         br = get_break(arg_str, from, until);
	 for( int j = from; j <= br; j++){
	  res_str[x+j] = arg_str[j];
	 };

	 res_str[x+br+1] = '\n';
	 x++; 

        	
    }while( until < len-1 );

   res_str[x+br] = '\0';
  
   
  printf("%s\n",res_str);
    



}

int get_break(char* str,int from, int until){

  int saved_until = until;

	while(until+1 != from) 
	  if(str[until--] != '-')
	   return until+1;


	return saved_until;

}
