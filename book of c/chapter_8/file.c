#include <fcntl.h>
#define PERMS 0666

#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20

typedef struct _c_iobuf {
int cnt;/* characters left */
char *ptr;/* next character position */
char *base;/* location of buffer */
int flag;/* mode of file access */
int fd;/* file descriptor */
} c_FILE;



extern c_FILE _iob[OPEN_MAX];

#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flags{
  _READ = 01,
  _WRITE= 02,
  _UNBUF =04,
  _EOF = 010,
  _ERR = 020
 };


int _c_fillbuf(c_FILE *);
int _c_flushbuf(int, c_FILE *);
#define feof(p) ((p)->flag & _EOF) != 0
#define ferror(p) ((p)->flag & _ERR) != 0
#define fileno(p) ((p)->fd)



#define getc(p) (--(p)->cnt >= 0 \
? (unsigned char) *(p)->ptr++ : _c_fillbuf(p))



#define putc(x,p) (--(p)->cnt >= 0 \
? *(p)->ptr++ = (x) : _c_flushbuf((x),p))
#define getchar() getc(stdin)
#define putcher(x) putc((x), stdout)



/* RW for owner, group, others */
 c_FILE *c_fopen(char *name, char *mode){
  int fd;
  c_FILE *fp;
   if (*mode != 'r' && *mode != 'w' && *mode != 'a')
    return NULL;
   for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
    if ((fp->flag & (_READ | _WRITE)) == 0)
     break;

     if (fp >= _iob + OPEN_MAX)
      return NULL;

      if (*mode == 'w')
       fd = creat(name, PERMS);
        else if (*mode == 'a'){
         if ((fd = open(name, O_WRONLY, 0)) == -1)
          fd = creat(name, PERMS);
          lseek(fd, 0L, 2);
          } else
             fd = open(name, O_RDONLY, 0);

        if (fd == -1)
         return NULL;

  fp->fd = fd;
  fp->cnt = 0;
  fp->base = NULL;
  fp->flag = (*mode == 'r') ? _READ : _WRITE;
   return fp;
}



/* _c_fillbuf: allocate and fill input buffer */
  int _c_fillbuf(c_FILE *fp){
   printf("fill..\n");
   int bufsize;
    if ((fp->flag&(_READ|_EOF)) != _READ){
     printf("1st EOF\n");
     return EOF;
    }

     bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
     if (fp->base == NULL)
      if ((fp->base = (char *) malloc(bufsize)) == NULL){
       printf("2nd EOF\n");
       return EOF;
      }


   fp->ptr = fp->base;
   fp->cnt = read(fp->fd, fp->ptr, bufsize);

 if (--fp->cnt < 0){

  if (fp->cnt == -1)
   fp->flag |= _EOF;
    else fp->flag |= _ERR;

   fp->cnt = 0;
   printf("3rd EOF\n");
   return EOF;
  }

  return (unsigned char) *fp->ptr++;
}


c_FILE _iob[OPEN_MAX] = {
/* stdin, stdout, stderr */
{ 0, (char *) 0, (char *) 0, _READ, 0 },
{ 0, (char *) 0, (char *) 0, _WRITE, 1 },
{ 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 }
};

int _c_flushbuf(int symbol, c_FILE * f){
 printf("flush..\n");
 f->ptr-=strlen(f->base);
 f->cnt = strlen(f->base);
}

int fclose(c_FILE *f){

return close(f->fd);

};

int fseek(c_FILE *fp, long offset, int origin){

int a = lseek(fp->fd,  offset, origin);
printf("seek #:%d\n:",a);


}
int main(int argc, char** argv){

char *p = argv[1];

c_FILE* f = c_fopen(p,"r");
_c_fillbuf(f);
fseek(f,0,0);

for(int i =0; i< 2;i++)
putc(65,f);







printf("%s %d\n",f->base,f->cnt);

};
