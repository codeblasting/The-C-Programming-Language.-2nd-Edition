#include <stdio.h>
#include <string.h>

typedef long Align;

typedef union header {

struct {
union header *ptr; 
unsigned size;
} s;
Align x;
}Header;

  static  Header base;
  static Header *freep = NULL;
  static Header *morecore(unsigned nu);

   void *malloc(unsigned nbytes){
     Header *p, *prevp;
    unsigned nunits;
    nunits = (nbytes+sizeof(Header)-1)/sizeof(union header) + 1;
     if ((prevp = freep) == NULL) {
      base.s.ptr = freep = prevp = &base;
      base.s.size = 0;
     }

  for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
   if (p->s.size >= nunits) { /* big enough */
    if (p->s.size == nunits) /* exactly */
     prevp->s.ptr = p->s.ptr;
    else {

     p->s.size -= nunits;
     p += p->s.size;
     p->s.size = nunits;
  }

    freep = prevp;
     return (void *)(p+1);
  }
   if (p == freep) /* wrapped around free list */
    if ((p = morecore(nunits)) == NULL)
     return NULL;
/* none left */
}
}


#define NALLOC 1024

 static Header *morecore(unsigned nu){
  char *cp, *sbrk(int);
  Header *up;
   if (nu < NALLOC)
    nu = NALLOC;
   cp = sbrk(nu * sizeof(Header));
   if (cp == (char *) -1)
    return NULL;
    up = (Header *) cp;
    up->s.size = nu;
     free((void *)(up+1));
   return freep;
  }


 /* free: put block ap in free list */
 void free(void *ap){
  Header *bp, *p;
  bp = (Header *)ap - 1;
   for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
   if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
   break; /* freed block at start or end of arena */
 if (bp + bp->s.size == p->s.ptr){
  bp->s.size += p->s.ptr->s.size;
  bp->s.ptr = p->s.ptr->s.ptr;
 }else
  bp->s.ptr = p->s.ptr;
   if (p + p->s.size == bp){
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
   }else
 p->s.ptr = bp;
 freep = p;
 }

void bfree(int p, int n){
 


}

void* calloc(int n,int size){

 return malloc(n*size);

}


 int main(){

 char *p = calloc(2,4);
 strcpy(p,"labas");
 printf("p: %s\n",p);


 };
