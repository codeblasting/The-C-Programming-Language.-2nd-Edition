#include <stdio.h>
#include <string.h>

int m = 2, n = 5;
char arg[99], res[99]; 
int arg_index = 0;
int res_index = 0;


main(int argc, char** argv){

   if(argc>1){

	   m = atoi(argv[1]);
	   n = atoi(argv[2]);
	   printf("m %d\nn %d\n",m,n);
	};


	scanf("%[^\n]",arg);
	printf("arg:%s\n",arg);
	
        
	while(arg[arg_index] != '\0')
         if(arg[arg_index] != ';')
          res[res_index++] = arg[arg_index++];
           else 
             {    
		  if(--m >= 0){
                    res[res_index++] = arg[arg_index++];    
                     continue;
                  }
                   
                 
                  for(int i = res_index, j  = res_index+n; i < j; i++)
                    res[res_index++] = '-';

                     arg_index++; 
		      
		     		     
	     }
		  
             
        printf("final res index %d\n",res_index);
        res[res_index] = '\0';
	printf("res:%s\n",res);
}



  
