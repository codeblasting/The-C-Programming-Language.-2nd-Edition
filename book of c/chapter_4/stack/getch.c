#include "getch.h"

int getch(void) /* get a (possibly pushed-back) character */
{ int result =  (bufp > 0) ? buf[--bufp] : getchar();
  return (result == '\'') ? EOF : (result == ';') ? '\n' : result;
};

void ungetch(int c)
/* push character back on input */
{
if (bufp >= BUFSIZE)
printf("ungetch: too many characters\n");
else
buf[bufp++] = c;
}
