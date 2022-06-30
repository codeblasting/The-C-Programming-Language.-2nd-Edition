#include <stdio.h>

int set_bits(unsigned x, int p, int n, int y);
int invert_bits(unsigned x, int p, int n);

int main(){

	int x = 0x00F1;
	int y = 0xAAA2;

	int r = set_bits(x,8,8,y);
	printf("%d\n",r);
      
	r = invert_bits(x,8,8);
	printf("%d\n",r);
	
        

}

int set_bits(unsigned x, int p, int n,int y){
         
        int mask = ~(-1 << n);

       y&=mask; 
       y<<=(p-n);
       y|=x;
       return y;       
};

int invert_bits(unsigned x, int p, int n){

        int mask = -1<< n; // /------/ --> /-----***/
        mask=~mask; // /-----***/ --> /*****---/
	mask<<=(p-n); // /*****---/ --> /***---***/
	int extracted_bits = x & mask; // /***&^^%***/
	int inverted_bits = (~extracted_bits)&mask; 
	
	mask=~mask; // /***---***/ --> /---***---/
	return  (x&mask)|inverted_bits; 
};



