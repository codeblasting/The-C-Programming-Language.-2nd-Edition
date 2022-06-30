#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){


 typedef struct _c_iobuf {
  int cnt;/* characters left */
  char *ptr;/* next character position */
  char *base;/* location of buffer */
  int flag;/* mode of file access */
  int fd;/* file descriptor */
  } c_FILE;

 c_FILE s = { 0, (char *) 0, (char *) 0, 0,1 };
 putc(65,&s);

};
