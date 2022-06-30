#include <stdio.h>

int i;
void remove_trail(char* arg);

main(){

char x[99];
for(i = 0; x[i-1] != '\n'; i++)
 x[i] = getchar();

x[i] = '\0';


printf("BEFORE_TRAIL:%s",x);
remove_trail(x);
printf("\nAFTER_TRAIL:%s\n",x);

};


void remove_trail(char* arg){

while( !(arg[i] > ' '))i--;

arg[i+1] = '\n';
arg[i+2] = '\0';

}
