#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int get_groups(char* src, char* group_array);
char* expand_group(char* group, int n);
void expand(char* s1, char* s2);


int main(){

	char* s1 = malloc(100);	
	char* s2 = malloc(100);
	scanf("%s",s1);
        expand(s1,s2);
	printf("s1: %s\ns2: %s\n",s1,s2);


         
};

int get_groups(char* src, char* group_array){

	int n = 0;
        int i = 0;

	while(src[i+1] != '\0'){
        
		char from = (src[i+1] == '-') ? (src[i]) : (src[++i]);
		char to   = src[i+=2];
		*(group_array++) = from;
		*(group_array++) = to;
		n++;
		
	};

	return n;

};

char* expand_group(char* groups, int n){
 
	char* group = malloc(50);
        char from = groups[n*2];
	char to = groups[(n*2)+1];
	int j = 0;

           for(int i = from; i <= to; i++)
              group[j++] = i;
	   
               group[j] = '\0';
               return group;
};

void expand(char* s1, char* s2){

       char* groups = malloc(50);
       int n = get_groups(s1,groups);

       for(int i = 0; i < n; i++){
        
	       char* group = expand_group(groups,i);
	       strcat(s2,group);

       }

};





