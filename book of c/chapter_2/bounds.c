#include <stdio.h>
#include <limits.h>


int main(){

signed short a = 1<<( (sizeof(signed short)*8) -1 );
printf("signed short min: %d\n",a);

signed short mask = ~a;
a >>= ( (sizeof(signed short)*8) -1 );
a &=  mask;
printf("signed short max: %d\n",a);

/*      */

unsigned short b = ~0;
printf("unsigned short max: %u\n",b);

/*      */

signed long c = sizeof(signed long)*8 ;
printf("signed long min: -(2^%d)\n",c);

c = sizeof(signed long)*8 - 1;
printf("signed long max: (2^%d)+(2^%d)-1\n",c,c);

/*      */

unsigned long ul = ~0;
printf("unsigned long max: %lu\n",ul);


/*      */




signed int d =  1<<( (sizeof(signed int)*8) -1 );
printf("signed int min: %d\n", d);

signed int mask1 = ~d;
d >>= ( (sizeof(signed int)*8) -1 );
d &=  mask1;
printf("signed int max: %d\n",d);

/*      */

unsigned int c1 = ~0;
printf("unsigned int max: %u\n",c1);

/*      */


signed char e = 1<<( (sizeof(signed char)*8) -1 );
printf("signed char min: %d\n",e);

signed char mask2 = ~e;
e >>= ( (sizeof(signed char)*8) -1 );
e &=  mask2;
printf("signed char max: %d\n",e);


/*      */


unsigned char f = ~0;
printf("unsigned char max: %d\n",f);

/*  ???? */
            
float g = 0x7FF00000; //positive infinty
printf("max float: %f\n",g+1);
g = 0xFFF00000; // negative infinity
printf("min float: %f\n",g);


return 0;

}
