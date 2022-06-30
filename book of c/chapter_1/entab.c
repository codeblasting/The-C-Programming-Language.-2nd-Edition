#include <stdio.h>
#include <string.h>

int width = 9;
char arg[99], res[99]; 
int arg_index = 0, res_index = 0;
int count_spaces(char* arg, int index);

main(){
		
	int tab_count = 0, 
	    space_count = 0,
	    after_count = 0;

	scanf("%s",arg);
	printf("entab arg:%s\n",arg);

	while(arg[arg_index] != '\0')
	{  
	   if(arg[arg_index] != '-')
	    res[res_index++] = arg[arg_index++];
             else{

	       space_count = count_spaces(arg,arg_index);
	       tab_count  = space_count / width;
	       after_count = space_count % width;

	        for(int i = 0; i < tab_count; i++)
		  res[res_index++] = '\t';
		for(int j = 0; j < after_count; j++)
	          res[res_index++] = '-';

		arg_index+= space_count;
		space_count = 0;

             }	       
	};

	printf("entab res:%s\n",res);



};

int count_spaces(char *arg, int index){

	int spaces = 0;
	while(arg[index++] == '-')
           spaces++;

     return spaces;
};
