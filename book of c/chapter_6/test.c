#include <stdio.h>

union {int x;
       float m;
      }a;

struct c {
int a:2;
int b:2;

} flags;



//1100
int main(){
flags.a = 2;
flags.b = 2;
printf("%d\n",!(flags.b));
//1111
//01001
//11
}
