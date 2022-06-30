#include <stdio.h>
#include <string.h>
#define COL 3
int string_to_bits(char* arg_str);
void bits_to_string(int arg_bits, char* arg_str,char* res_str);
void push_bit(int arg_bit,int* dest_int,int where);
void print_bin(int arg_int);
int bit_flip(int arg_bits);
int get_rbit(int arg_bits, int at);
int log2(int arg);
int make_mask();
int shift_r(int arg, int count);

main(){
       
       char str[99];
       scanf("%[^\n]",str); 
       int res = string_to_bits(str);
       int x = bit_flip(res);

       char result_string[99];
       bits_to_string(x,str,result_string);
       printf("%s",result_string); 
      return; 
};

int shift_r(int arg, int count){
	if(count == 0)return arg;
	int mask = 0xFFFFFFFF <<(32-count);
	arg >>= count;
	int result = arg & ~mask;
	return result;
}

int string_to_bits(char* arg_str){
    
    int ret_int = 0;

	for(int i = 0; i < strlen(arg_str); i++)
		if(arg_str[i] == '-')
		    push_bit(0,&ret_int,i);
		      else push_bit(1,&ret_int,i);

	return ret_int;



};

void bits_to_string(int arg_bits,char* arg_str,char* ret_str){
        
	int len = strlen(arg_str);
	int mask = 1<<31;
	int i = 0;
        int j = 0;
	while ( j < len ){

            ret_str[i++] = arg_str[j++];
	    if( (mask&arg_bits) != 0 )
	      ret_str[i++] = '\n';

	    mask = shift_r(mask,1);
	}

	ret_str[i]= '\0';
         return ret_str;	 
}

int make_mask(){
   int shift_count = 32 - COL;	
   int x = (0xFFFFFFFF << shift_count);
   return x;
}
void push_bit(int arg_bit, int* dest_int,int where){
    
	int c_index = where;
        int bit_mask = arg_bit << (31 - c_index);
        *dest_int = *dest_int | bit_mask;
        c_index++;	
};


void print_bin(int arg_int){
 
	for(int i=31; i>=0; i--)
	  if(arg_int & (1<<i))
            printf("%d",1);
	     else printf("%d",0);

};


int get_rbit(int arg_bits, int at){
     
      int mask = make_mask();
      mask = shift_r(mask,at);
      arg_bits &= mask;

      int rmost_bit = arg_bits & -arg_bits;
      int retval = log2(mask) - log2(rmost_bit);

      
           return retval;
         

}

int log2(int arg){
//if(arg==0)return -1;

int nlz = 0;
int mask = 1<<31;
while( (arg&mask) == 0 )
    {
	 arg<<=1;
	 nlz++;
    }

return 31-nlz;

}

int bit_flip(int arg_bits){
 
	int shift_offset = 0;
	int last_shift = 0;
        int mask = make_mask();
	int end_mask = shift_r(mask,32-COL);
	int res_bits = 0;
	int ri=-1;
     
      do{
	int result = mask & arg_bits;
	if(result == 0){ 
		last_shift = COL;
		mask = shift_r(mask,last_shift);
		shift_offset += last_shift;
	}else{
	 
           last_shift = get_rbit(arg_bits,shift_offset)+1;
	   mask = shift_r(mask,last_shift);
	   shift_offset += last_shift;
	} 
	  for(int i =0,r=r+1;i<last_shift;i++,ri++)
	   push_bit(0,&res_bits,ri);
	  push_bit(1,&res_bits,ri);
	    
      }while(mask>=end_mask); 
      return res_bits;
}
