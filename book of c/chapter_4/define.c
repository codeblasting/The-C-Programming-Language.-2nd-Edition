#include <stdio.h>
#define dprint(expr) printf(#expr " = %d\n", expr)
#define paste(front, back) front ## back

#define swap(t,a,b) t temp = a; a = b; b = temp; 

 main(){

 int a = 2;
 int b = 3;
 printf("%d %d\n",a,b);

 swap(int,a,b);

 printf("%d %d\n",a,b);


}
