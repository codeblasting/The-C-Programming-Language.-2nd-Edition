#include <stdio.h>
#include <stdlib.h>

main(int argc, char** argv){


int m[100];
float sum = 0;
int length = argc - 1;

for(int i = 0; i < length; i++){
    m[i] = atoi(argv[i+1]);
    sum += m[i];
}



for(int i = 0; i < length; i++)
  printf("%.0f ",m[i]/sum*100/2);

  printf("\n");
    


		

}
