#include <stdio.h>

main(){

for(int c = getchar(); c != EOF; c = getchar()){
    
	(c == '\t')&&printf("[t]\n")
	|| (c == '\n')&&printf("[n]\n")
	   || (c == '\b')&&printf("[bsp]\n")
	      ||(c == '\\')&&printf("[bs]\n")
	        ||(c == ' ')&&printf("[s]\n")
		  ||(c == '\0')&&printf("[0]\n")
	            ||putchar(c);


	
}
   putchar('\n');
}
