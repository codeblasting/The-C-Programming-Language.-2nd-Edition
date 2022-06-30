#include <stdio.h>

float ftoc(f);

main(){ 
	
// C = (5/9)(F-32);
// F = C/(5/9)+32;

	printf("%s\n","---------------");
       for(int fhr = 0; fhr <= 300;fhr+=20){
       printf("%3d%6.1f\n",fhr, ftoc(fhr) );
       }

}

float ftoc(f)
 { char* x = "//labas";
   char* y = "/* comment */";
   char c = '//'; 
  return 
   (5.0/9.0)*(f-32);
}
