#include <stdlib.h>
#include "lines.h"

int match_m0(char* str, int at);
int match_m1(char* str, int at);
int match_s(char* str, int at);
int match_nl(char* str, int at);
void remove_comments(char* str);

int main(){

char file_name[90];
scanf("%s",&file_name);
char r_str[900];
getLines(file_name,r_str);
remove_comments(r_str);
printf("%s\n",r_str);

}

int match_m0(char* str, int at){
       
       if(str[at]=='/')
	if( (str[at-1]!='\"') || (str[at-1]!='\'') )
	 if(str[at+1]=='*')
	  return 1;

  return 0;       

};

int match_m1(char* str, int at){
       
       if(str[at]=='*')
	if( (str[at-1]!='\"') || (str[at-1]!='\'') )
	 if(str[at+1]=='/')
	  return 1;
       
  return 0;       
};

int match_s(char* str, int at){

        if(str[at]== '/')
         if(str[at+1]=='/')
	  if( (str[at-1]!='\"') || (str[at-1]!='\'') )
	   return 1;
  
  return 0;
};

int match_nl(char* str, int at){

       if( (str[at]== '\0')||(str[at]=='\n') )
	 return 1;
   
   return 0;
};

void remove_comments(char* str){

 int index = 0;
 while(index < strlen(str))
 {
      if(match_m0(str,index)){
        while(!match_m1(str,index))
 	 str[index++] = ' ';
	
        str[index++] = ' ';
	str[index] = ' ';
      } 
 
      if(match_s(str,index))
       while(!match_nl(str,index))
 	str[index++] = ' ';


      
       
      index++;
 };


};
       


