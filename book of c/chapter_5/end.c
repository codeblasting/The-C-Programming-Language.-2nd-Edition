#include <stdio.h>
#include <string.h>

int end(char*,char*);

 main(){

	 char* a = "labasvakar";
	 char* b = "ar";
	 int c = end(a,b);
	 printf("c %d\n",c);

};


int end(char *s,char *t){

	int i = strlen(t)+1;
	s += strlen(s);
	t += strlen(t);

	for(; ;s--,t--,i--)
	 if(*s!=*t)
	  break;

	return i ? 0 : 1;

}


