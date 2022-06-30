#include <stdio.h>
#include <string.h>

int tab_stops[] = {5,9,12,18,22};
int tab_index = 0;
int tab_stop = 5;
int width = 9;
char arg[99], res[99]; 

main(){


	scanf("%[^\n]",arg);
	printf("arg:%s\n",arg);
	for(int i = 0, i0 = 0; i < strlen(arg); i++,i0++)
	 if(arg[i] != '\t'){
	    if(i0==tab_stop)tab_stop = tab_stops[++tab_index]; 
	    res[i0] = arg[i];
	 }
	     else 
	      for(int j = i0; (j < width+i0) || 0*(i0 = j-1); j++)
		if(j==tab_stop){
		 tab_stop = tab_stops[++tab_index];
		 i0 = j-1;
	         break;}
	          else res[j] = '-';
	     
	 


	printf("result:%s\n",res);
}
  
