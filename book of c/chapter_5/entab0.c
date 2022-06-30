#include <stdio.h>
#include <string.h>

int m = 2;int n = 5;
char arg_string[99], res_string[99]; 
int arg_index = 0, res_index = 0;

main(int argc, char** argv){

	if(argc>1){

		m = atoi(argv[1]);
		n = atoi(argv[2]);
		printf("m %d\nn %d\n",m,n);
	};
	
	scanf("%s",arg_string);
	printf("entab arg_string:%s\n",arg_string);

	while(arg_string[arg_index] != '\0')
	{   

	 if(arg_string[arg_index] != '-'){
	   if( arg_index == n-1 || (1+arg_index)%n == 0 ) 
	    m--;
	    res_string[res_index++] = arg_string[arg_index++];
	 }
           else{
                int old_res_index = res_index;
		     while(arg_string[arg_index] == '-' && arg_string[arg_index] != '\0'){
			if( arg_index == n-1 || (1+arg_index)%n == 0 ){
			 
			  if(m-- <= 0){
			   res_index = old_res_index+1;	
			   res_string[res_index++] = ';';
			   arg_index++;
			   break;
			 };
			  old_res_index = res_index;
			};
	             res_string[res_index++] = arg_string[arg_index++];
		     
		     };
		     
	       };
        
        };	       
	
        res_string[res_index] = '\0';
	printf("entab res_string:%s\n",res_string);

         return 0;

};

