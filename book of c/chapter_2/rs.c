#include <stdio.h>

int rotate_right(unsigned x, int n){

	return (x>>n) | (x<<(32-n));

};

int main(){

	int arg = 1;
	int result = rotate_right(arg,33);
	printf("%d\n",result);

};




