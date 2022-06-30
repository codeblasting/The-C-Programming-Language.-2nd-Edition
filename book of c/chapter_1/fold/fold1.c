#include <stdio.h>
#include <string.h>
#define COL 3
int read_into( char* str );
int last_nonblank( char* str, int current_index, int last_break );
int last_blank( char* str, int current_index, int last_break );

main(){
        
	char arg_str[99],
	     res_str[99];

	int arg_index = 0,
	    res_index = 0,
	    arg_max = read_into ( arg_str );
        

	int last_break = -1;
	while( arg_index <= arg_max ){

		res_str[res_index] = arg_str[arg_index];

		if( last_nonblank( arg_str, arg_index, last_break)!= -1 ){
		     last_break = arg_index;
		     res_str[++res_index] = '\n';
		}

		   else
		
		if( last_blank( arg_str, arg_index, last_break)!= -1 ){
                      
		      if(arg_max != arg_index){
		     last_break = arg_index;
		     res_str[++res_index] = '\n';
		      }
                };
		    
		

		res_index++;
		arg_index++;
	} 

        res_str[res_index] = '\0';
	printf("%s\n",res_str);

}

	
int read_into( char* str ){

	int index = 0;
	char c;

	do{
            c = getchar();
	    if(c=='\n')
		break;
	    str[index++] = c;
	}while(1);

	return index - 1;

	
}


int last_nonblank( char* str, int current_pos, int last_break ){
        
	int is_blank = str[current_pos] == '-';
	 if( is_blank )
	   return -1;
        
	
	int is_on_col = (current_pos - last_break) == COL; 
	 if( is_on_col == 1 )
	  return 1;

	
         
       	
	 int is_last = 0;
	 //does it have enough blanks ahead?
	for(int i = current_pos+1; i <=  (last_break + COL) ;i++) 
	   if(str[i] == '-')
	     is_last = 1;
	      else {is_last = 0; break;}

         if(is_last)
	  return 1;
           return -1;
	
}


int last_blank( char* str, int current_pos,int last_break){

	if ( str[current_pos] != '-' )
	return -1;
	
	int is_on_col = (current_pos - last_break) == COL;
	 if( is_on_col == 1 )
	  return 1;
	   return -1;
	

}
