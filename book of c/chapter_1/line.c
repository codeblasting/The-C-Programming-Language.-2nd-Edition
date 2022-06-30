#include <stdio.h>
#define MAXLINE 10


/*Write a program to remove trailing blanks and tabs from each line of input, and
to delete entirely blank lines.*/


/* maximum input line length */
int get_line(char line[], int maxline);
void copy(char to[], char from[]);
main()
{
int len;
char line[MAXLINE];
char longest[MAXLINE];
int max = 0;
while ((len = get_line(line, MAXLINE)) > 0){
if (len > max) {
max = len;
copy(longest, line);
}


}
if (max > 0) /* there was a line */
printf("\nlongest:%s", longest);
return 0;
}
int get_line(char s[],int lim)
{
int c, i;
for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
s[i] = c;
if (c == '\n') {
s[i] = c;
++i;
}
s[i] = '\0';
return i;
}

void copy(char to[], char from[])
{
int i;
i = 0;
while ((to[i] = from[i]) != '\0')
++i;
}
