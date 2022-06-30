#include <string.h>
#include <stdio.h>
#define COL 3
#define MAX_VAL (1<<COL-1) + ( (1<<COL-1)-1 )

void make_table(int* arg_array);
int log2(int arg_int);
int get_value(int arg_int);
int send_bits(char* arg,int index);
void push_bit(int arg_bit,int* dest_int,int where);

int main(){

        char arg[90];
	scanf("%[^\n]",arg);
        char res[90]; 
   	
        int table[100];
	make_table(table);

	 int index = 0;
	 int i = 0, j = 0;

	 while(index<strlen(arg)){
           
		 int key = send_bits(arg,index);
                 int val = table[key]; 

		 while(j <= index+val)
		  res[i++] = arg[j++];

	         res[i++] = '\n';
		 index+=val+1;
	 };

	printf("%s\n",res);
     
        return;
};

int send_bits(char* arg, int index){
     
    int res_bits = 0;
     for(int i = index, j = 1; i < index+COL; i++,j++){
      if(arg[i] == '-')
       push_bit(0,&res_bits,j);
        else push_bit(1,&res_bits,j);
      }

  res_bits>>=(31-COL);
  return res_bits;

 }


void push_bit(int arg_bit, int* dest_int,int where){
    
	int c_index = where;
        int bit_mask = arg_bit << (31 - c_index);
        *dest_int = *dest_int | bit_mask;
        c_index++;	
};

int log2(int arg_int){

	int nlz = 0;
	int mask  = 1 << 31;
	while( (mask&arg_int) ==0)
	 { nlz++; 
	   arg_int<<=1;
	 };
	return 31-nlz;

}

int get_value(int arg_int){
  if(arg_int == 0) return log2(MAX_VAL);
  return log2(MAX_VAL) - log2(arg_int&-arg_int);	
}

void make_table(int* arg_array){

	int i = 0;
	while(i <= MAX_VAL){
	  arg_array[i] = get_value(i);
	  i++;
	}
	return;

}

