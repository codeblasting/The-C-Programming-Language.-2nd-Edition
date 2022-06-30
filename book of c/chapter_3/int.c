#include <string.h>
#include <stdio.h>
#include <limits.h>

void itoa(int n, char s[], int w);
void reverse(char* s);

int main(){
  
char x[20];
int biggest_negative = 1<<31;
itoa(biggest_negative,x,14);
printf("%s\n",x);
  


};

void reverse(char s[])
{
int c, i, j;
for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
c = s[i];
s[i] = s[j];
s[j] = c;
}
}

void itoa(int n, char s[], int w){

 int i, sign;
 int limit = 0;
  if ((sign = n) < 0) /* record sign */
   if(n==(1<<31)){
	   limit = 1;
	   n = (1<<30)+((1<<30)-1);
   }else
     n=-n;
     /* make n positive */
  
  i = 0;
  do {
   /* generate digits in reverse order */
      if(limit){ limit = 0; s[i++] = '8'; continue; }	 
      s[i++] = n % 10 + '0'; /* get next digit */
     } while ((n /= 10) > 0);
       /* delete it */
         if (sign < 0)
          s[i++] = '-';
 
  s[i] = '\0';

  if(i<w)
   for(int j = 0; j < (w-i); j++)
     strcat(s,"_");

  reverse(s);
  
}
