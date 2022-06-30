#include <stdio.h>
main(){ 
	
// C = (5/9)(F-32);
// F = C/(5/9)+32;

	printf("%s\n","---------------");
       for(int celsius = 300; celsius != 0;celsius-=20){
       printf("%3d%6.1f\n",celsius, celsius/(5.0/9.0)+32);
       }

}
