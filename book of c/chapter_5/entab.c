#include <stdio.h>
#include <string.h>

int tab_stops[] = {5,8,12,15,-1};
int *current_tab = tab_stops;

char arg_string[99], res_string[99]; 
int arg_index = 0, res_index = 0;

main(int argc, char** argv){
		


	if(argc>1){
	   
	   int i;
           for(i = 1; i < argc; i++)
	    tab_stops[i-1] = atoi(argv[i]);

	   tab_stops[i-1] = -1;
	  
	   for(int j = 0; j < i; j++)
	     printf("tab stop: %d\n",tab_stops[j]);
	};

	
	scanf("%s",arg_string);
	printf("entab arg_string:%s\n",arg_string);

	while(arg_string[arg_index] != '\0')
	{   
	 if(arg_string[arg_index] != '-'){

	  if(arg_index == *current_tab)
	   if(*current_tab!=-1)
	    current_tab++;

	    res_string[res_index++] = arg_string[arg_index++];
	   }
             else{
                int old_res_index = res_index;
		     while(arg_string[arg_index] == '-' && arg_string[arg_index] != '\0'){
			if(arg_index == *current_tab && *current_tab!=-1){
			  printf("current tab %d\n",*current_tab);
			  res_index = old_res_index;
			  res_string[res_index++] = ';';
			   current_tab++;
			   arg_index++; 
			   break;
			};
	             res_string[res_index++] = arg_string[arg_index++];
		     };
		     
	       };
        
        };	       
	
        res_string[res_index] = '\0';
	printf("entab res_string:%s\n",res_string);

         return 0;

};

