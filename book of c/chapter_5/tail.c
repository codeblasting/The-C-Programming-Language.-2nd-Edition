#include <stdio.h>
#include <string.h>
#define MAXLINES 5000 /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int nlines,char*);
void writelines(char *lineptr[], int nlines);
int n = 10;
/* sort input lines */
main(int argc, char** argv)
{
	if(argc == 2)
	 n = atoi(argv[1]);

	printf("n is %d\n",n);

#define MAX_BUFF_INDEX 5000
char buffer[MAX_BUFF_INDEX];

int nlines;
/* number of input lines read */
if ((nlines = readlines(lineptr, MAXLINES,buffer)) >= 0) 
writelines(lineptr, nlines);


}
#define MAXLEN 1000 /* max length of any input line */
int get_line(char *, int);


/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char* buff)
{
int len, nlines;
char *p = buff, line[MAXLEN];
nlines = 0;
while ((len = get_line(line, MAXLEN)) > 0)
if (nlines >= maxlines || (p += len) > (buff+MAX_BUFF_INDEX))
return -1;
else {
line[len-1] = '\0'; /* delete newline */
strcpy(p, line);
lineptr[nlines++] = p;
}
return nlines;
}
/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
int i;
for (i = nlines-1; i!=-1 && n!= 0; i--,n--)
printf("%s\n", lineptr[i]);
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


