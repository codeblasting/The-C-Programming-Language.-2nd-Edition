
#include "stack.h"


 main(int argc, char** argv){

  char cmd[100];
  

  for(int i = 1; i < argc; i++){
   strcat(cmd,argv[i]);
   strcat(cmd," ");
   };
  
 if(strlen(cmd)>0){
  strcat(cmd,";'");
  ungets(cmd);
 };

  stack_loop();
  
 }



