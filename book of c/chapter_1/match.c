#include <stdio.h>
#include <string.h>
#include "lines.h"

char str[200];
char filename[99];

int scan(char* c0, char*c1,int index);
int str_match(char* match,int index);
void print_mismatches(char* c0, char* c1);
void print_error(char* c,int index);

int main(){

scanf("%s",filename);
getLines(filename,str);
printf("%s\n",str);
print_mismatches("{","}");
print_mismatches("[","]");
print_mismatches("\"","\"");
print_mismatches("\'","\'");
print_mismatches("<","/>");

};




int scan(char* c0, char* c1,int index){
        
	char limiter = '\0'; 
	while(str[index++] != limiter)
          if(str_match(c0,index))
           return index;
            else if(str_match(c1,index))
	     return index;

      return (str[index-1]==limiter) ? -1 : index; 
};

int str_match(char* match,int index){
     
	for(int i = 0;i<strlen(match);)
         if(match[i++] != str[index++])
	   return 0;

         while(str[index]!= '/' && str[index-1]!= '/')
	   if(str[index--] == '\n' || index == 0){
	      return 1;
	   }	   


      return 0;	
}

void print_mismatches(char* c0, char* c1){

      int index = 0;
      int x;

       while((x = scan(c0,c1,index)) != -1){ 
	
	  if(str_match(c0,x)){
	    int y = scan(c1,c0,x);
	    if(str_match(c1,y))
	     index=y+1;
	      else{
		     print_error(c0,x); 
		     index=y-1;
		  };
	   }else if(str_match(c1,x)){

                     index = x+1;
		     print_error(c1,x);
	               }
      };

}


void print_error(char* c, int index){

	int line = 0;
	int x = 0;
	while(x++ < index)
	 if(str_match("\n",x))
	  line++;

	   printf("mismatch of %s at line %d \n",c,line);
};



