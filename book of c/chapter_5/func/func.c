#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 5000
#define MAXLEN 5000
#define MAX_BUFF_INDEX 5000


char *lineptr[MAXLINES];
char buff[999];
/* max #lines to be sorted */
/* pointers to text lines */
void swap(void *v[], int, int);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void q_sort(void *lineptr[], int left, int right,
int(*ptr)());
int cmp(char *, char *);
int numcmp(char *s1, char *s2,int first);

     int numeric = 0;
     int reverse = 0;
     int fold    = 0;
     int compare = 0;
     int dir     = 0;

     int field_start = 0;
     int field_end   = 0;


  main(int argc, char *argv[]){
  
    int nlines;

   for(int i = 0; i < argc; i++){
     if(strcmp(argv[i], "-n") == 0)numeric = 1;
     if(strcmp(argv[i], "-r") == 0)reverse = 1;
     if(strcmp(argv[i], "-f") == 0)fold    = 1;
     if(strcmp(argv[i], "-c") == 0)compare = 1;
     if(strcmp(argv[i], "-d") == 0)dir     = 1;
   };
      
   
   if(argc>2){ 
    field_start = strtol(argv[argc-2],0,10);
    field_end   = strtol(argv[argc-1],0,10);
   };
   
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {

     void (*ptr)();
           
           ptr = strcmp;
	   if(numeric)ptr = numcmp;
	   if(compare)ptr = cmp;
	   if(fold)ptr = strcasecmp;
	   if(dir && fold)ptr = strncasecmp; 

     q_sort((void**) lineptr, 0, nlines-1,ptr);
      
      writelines(lineptr, nlines);
      return 0;
    } else {
     printf("input too big to sort\n");
     return 1;
     }
   }


   /* q_sort: sort v[left]...v[right] into increasing order */
    void q_sort(void *v[], int left, int right,
     int(*ptr)()){
      int i, last;
      void swap(void *v[], int, int);
      if (left >= right)
        /* do nothing if array contains */
       return;
        /* fewer than two elements */
        swap(v, left, (left + right)/2);
        last = left;
         for (i = left+1; i <= right; i++){
          
	  field_end = dir ? 1 : 0;
	  
          int result = (*ptr)(v[i]+field_start, 
			      v[left]+field_start, 
			       field_end);
	  
	   int condition = reverse ? ( result > 0 ) : ( result < 0 );  
          if(condition) 
	   swap(v, ++last, i);
	 };

	  swap(v, left, last);
          q_sort(v, left, last-1, ptr);
          q_sort(v, last+1, right,ptr);
      }

   /* numcmp: compare s1 and s2 numerically */
     int numcmp(char *s1, char *s2, int first){
      double v1, v2;
      v1 = first ? s1[0]-48 : atof(s1);
      v2 = first ? s2[0]-48 : atof(s2);
       if (v1 < v2)
        return -1;
      else if (v1 > v2)
       return 1;
      else
       return 0;
     }

    int cmp(char *s1, char *s2){
	 if(strlen(s1) < strlen(s2))
	  return -1;
	   if(strlen(s1) > strlen(s2))
	    return 1;
	     else 
	      return 0;
	  }; 

    void swap(void *v[], int i, int j){
     void *temp;
     temp = v[i];
     v[i] = v[j];
     v[j] = temp;
    }





/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines){
 int len, nlines;
  char *p = buff, line[MAXLEN];
   nlines = 0;
 while ((len = get_line(line, MAXLEN)) > 0)
  if (nlines >= maxlines || (p + len) > (buff+MAX_BUFF_INDEX))
   return -1;
 else{ 
  line[len-1] = '\0';
   
   strcpy(p,line);
   lineptr[nlines++] = p;
   p+=len;
  };

return nlines;
};


int get_line(char s[],int lim){
 int c, i;
  for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
   s[i] = c;
 if (c == '\n'){
  s[i] = c;
  ++i;
 };
  s[i] = '\0';
  return i;
}

void writelines(char *lineptr[], int nlines){
 int i;
  for (i = 0; i < nlines; i++)
   printf("%s\n", lineptr[i]);
 }










