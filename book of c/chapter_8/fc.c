#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void filecopy(int, int);
main(int argc, char *argv[]){

int fp;

if (argc == 1) /* no args; copy standard input */
filecopy(0, 1);
else
while(--argc > 0)
if ((fp = open(*++argv, 0, 0)) == -1) {
printf("cat: can't open %s\n", *argv);
return 1;
} else {
filecopy(fp, 1);

}
return 0;
}

void filecopy(int from, int to)
{

char buf[BUFSIZ];
int n;
while ((n = read(from, buf, 1)) > 0)
write(to, buf, n);


return 0;

}
