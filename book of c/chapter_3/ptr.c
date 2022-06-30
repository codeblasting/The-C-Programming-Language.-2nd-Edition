#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void test(char* s){

	*(s++) = 65;
	*(s)   = 0;

}


int main(){

	char* s = malloc(50);
       
	*(s++) = 65;
	*(s)   = 0;
	printf("%s\n",s);

	test(s);
	printf("%s\n",s);


}
