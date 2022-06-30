#include <stdio.h>
#include <string.h>

int tab_stops[] = {5,9,12,18,22,-1};
int *current_tab = tab_stops;
char arg[99], res[99]; 
int arg_index = 0;
int res_index = 0;


main(int argc, char** argv){

   if(argc>1){
	   
	   int i;
           for(i = 1; i < argc; i++)
	    tab_stops[i-1] = atoi(argv[i]);

	   tab_stops[i-1] = -1;
	  
	   for(int j = 0; j < i; j++)
	     printf("tab stop: %d\n",tab_stops[j]);
	};


	scanf("%[^\n]",arg);
	printf("arg:%s\n",arg);
	
        
	while(arg[arg_index] != '\0')
         if(arg[arg_index] != ';')
          res[res_index++] = arg[arg_index++];
           else 
             {   
                 for(; res_index <= *(current_tab); res_index++)
                   res[res_index] = '-';
		  
		  current_tab++;
		  arg_index++;
		  
             }

        res[res_index] = '\0';
	printf("result:%s\n",res);
}



  
