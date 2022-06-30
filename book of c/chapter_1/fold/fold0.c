#include <stdio.h>
#include <string.h>

#define COL 3
#define MAX 100

int get_last(char* arg, int from, int until);
void get_breaks(char* arg, int results[]);
void read_into(char str[]);

main(){

	char arg[MAX]; 
	char res[MAX+10];
        int breaks[99];
	read_into(arg);
        get_breaks(arg,breaks);
        int line_break = breaks[0];

	for( int i = 0, j = 0, k = 0; j < strlen(arg) || 0*(res[i] = '\0'); )
	     if(j!=line_break)
	      res[i++] = arg[j++];
             else { 
                    res[i++] = '\n';
		    line_break = breaks[++k];
	     };	     

       	printf("%s\n",res);

};

void read_into(char str[]){
     
	int arg_index = 0;
	char c;

	do{ c = getchar();
            str[arg_index++] = c;
	  }while(c!='\n');

	str[arg_index-1] = '\0';
};


int get_last(char *arg, int from, int until){
     
     if(until > strlen(arg))until = strlen(arg);
     int last = until-1;
	for(int i = from; i < until; i++)
	   if(arg[i] != '-')
	    last = i;
        
	return last+1;
};


void get_breaks(char* arg, int results[]){

     int index = 0,
     res_index = 0;

     while(index < strlen(arg))
      {  
	 int n = get_last(arg,index,index+COL);
	 index=n;
	 results[res_index++] = n; 
      }

     results[res_index] = -1;
}
