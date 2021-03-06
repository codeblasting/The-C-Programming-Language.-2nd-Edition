#include <stdio.h>
#include <string.h>
#include <sys/dir.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>



#define NAME_MAX 14

typedef struct{
long ino;
char name[NAME_MAX+1];
} Dirent;





void fsize(char *);

main(int argc, char **argv)
{
if (argc == 1) 
fsize(".");
else
while (--argc > 0)
fsize(*++argv);
return 0;
}


/* fsize: print the name of file "name" */
void fsize(char *name)
{
struct stat stbuf;
if (stat(name, &stbuf) == -1) {
fprintf(stderr, "fsize: can't access %s\n", name);
return;
}
if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
dirwalk(name, fsize);
printf("%8ld %s \n", stbuf.st_size, name);
}

#define MAX_PATH 1024
/* dirwalk: apply fcn to all files in dir */
void dirwalk(char *dir, void (*fcn)(char *))
{
char name[MAX_PATH];
Dirent *dp;
DIR *dfd;

if ((dfd = opendir(dir)) == NULL) {
fprintf(stderr, "dirwalk: can't open %s\n", dir);
return;
}
while ((dp = readdir(dfd)) != NULL) {
if (strcmp(dp->name, ".") == 0
|| strcmp(dp->name, ".."))
continue;
/* skip self and parent */
if (strlen(dir)+strlen(dp->name)+2 > sizeof(name))
fprintf(stderr, "dirwalk: name %s %s too long\n",
dir, dp->name);
else {
sprintf(name, "%s/%s", dir, dp->name);
(*fcn)(name);
}
}
closedir(dfd);
}



















