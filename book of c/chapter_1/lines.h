#include <stdio.h> //this is comment
#include <string.h> /* this is comment two
		       and three */
int getLines(char* filename,char* r_lines){
  FILE* file = fopen(filename,"r");
  //comment
  size_t length = 0;
  int index = 0;/* lines comment
  yo yo "string" */
  char* current_line; 
  while(getline(&current_line,&length,file)!=-1){
   strcat(r_lines,current_line);
  }
  fclose(file);
  return index;
}


