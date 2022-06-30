#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(keytab[0]))


int bin_search(char *, struct key[], int);
int getword(char *, int);
/* count C keywords */


struct key {
char *word;
int count;
} keytab[] = {
"#define"  , 0,
"auto", 0,
"break", 0,
"case", 0,
"char", 0,
"const", 0,
"continue", 0,
"default", 0,
/* ... */
"size_t", 0,
"unsigned", 0,
"void", 0,
"volatile", 0,
"while", 0
};

main(){
int n;
char word[MAXWORD];
while (getword(word, MAXWORD) != EOF)
if (isgraph(word[0]))
if ((n = bin_search(word, keytab, NKEYS)) >= 0)
keytab[n].count++;
for (n = 0; n < NKEYS; n++)
if (keytab[n].count > 0)
printf("%4d %s\n",
keytab[n].count, keytab[n].word);
return 0;
}
/* binsearch: find word in tab[0]...tab[n-1] */
int bin_search(char *word, struct key tab[], int n)
{
printf("word in search %s\n",word);
int cond;
int low, high, mid;
low = 0;
high = n - 1;
while (low <= high) {
mid = (low+high) / 2;
if ((cond = strcmp(word, tab[mid].word)) < 0)
high = mid - 1;
else if (cond > 0)
low = mid + 1;
else
return mid;
}
return -1;
}


/* getword: get next word or character from input */
int getword(char *word, int lim)
{
int c, getch(void);
void ungetch(int);
char *w = word;
while (isspace(c = getch()))
;
if (c != EOF)
*w++ = c;
if (!isgraph(c)) {
*w = '\0';
return c;
}
for ( ; --lim > 0; w++)
if (!isgraph(*w = getch())) {
ungetch(*w);
break;
}
*w = '\0';

return word[0];
}
