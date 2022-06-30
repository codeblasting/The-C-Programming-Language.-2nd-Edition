#include <stdio.h>
#include <string.h>

int match(char c, char* str);

int main(){

	char s[99] = "geras metas";
	char s1[99] = "ara";

        int i, j;
        for (i = j = 0; s[i] != '\0'; i++)
          if(match(s[i],s1)==-1)
            s[j++] = s[i];

       s[j] = '\0';
       printf("%s\n",s);       

};


int match(char c, char*str){

	for(int i = 0; i<strlen(str); i++)
	  if(str[i] == c)
	    return i;

	return -1; 

    };
