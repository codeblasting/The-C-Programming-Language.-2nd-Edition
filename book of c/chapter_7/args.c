#include <stdarg.h>
#include <stdio.h>
/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
va_list ap; /* points to each unnamed arg in turn */
char *p, *sval;
int ival;
char c;
double dval;
va_start(ap, fmt); /* make ap point to 1st unnamed arg */
for (p = fmt; *p; p++) {
if (*p != '%') {
putchar(*p);
continue;
}
switch (*++p) {
case 'd':
ival = va_arg(ap, int);
printf("%d", ival);
break;
case 'f':
dval = va_arg(ap, double);
printf("%f", dval);
break;
case 's':
for (sval = va_arg(ap, char *); *sval; sval++)
putchar(*sval);
break;
case 'c':
 c = va_arg(ap, int);
 putchar(c);
break;
default:
putchar(*p);
break;
}
}
va_end(ap); /* clean up when done */

};


void minscanf(char *fmt, ...)
{
va_list ap; /* points to each unnamed arg in turn */
char *p, *sval;
void* ival;
void* dval;

va_start(ap, fmt); /* make ap point to 1st unnamed arg */
for (p = fmt; *p; p++) {
if (*p != '%') {
putchar(*p);
continue;
}
switch (*++p) {
case 'd':
ival = va_arg(ap, void*);
scanf("%d", ival);
break;
case 'f':
dval = va_arg(ap, void*);
scanf("%f", dval);
break;
case 's':
sval = va_arg(ap, char*);
scanf("%s",sval);
break;
case 'c':
 sval = va_arg(ap, char*);
 scanf("%c", sval);
default:
break;
}
}
va_end(ap); /* clean up when done */

};



int main(){

char c;
minscanf("%c",&c);
minprintf("%c\n",c);


float f;
minscanf("%f",&f);
minprintf("%f\n",f);


int d;
minscanf("%d",&d);
minprintf("%d\n",d);

char s[30];
minscanf("%s",s);
minprintf("%s\n",s);





};
