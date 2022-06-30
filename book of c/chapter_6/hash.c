#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HASHSIZE 10

 struct nlist {
   struct nlist *next;
   char *name;
   char *defn;
 };

static struct nlist *hashtab[HASHSIZE];

struct nlist *lookup(char *);
void undef(char*, char*);
char* replace(char *t,char* , char * );




 unsigned hash(char *s){
  unsigned hashval;
  for (hashval = 0; *s != '\0'; s++)
   hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
 }



 struct nlist *lookup(char *s){
  struct nlist *np;
  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
  if (strcmp(s, np->name) == 0)
   return np;

   return NULL;
 
 }





   struct nlist *install(char *name, char *defn){
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL){ 
     np = (struct nlist *) malloc(sizeof(*np));
     if (np == NULL || (np->name = strdup(name)) == NULL)
     return NULL;
     hashval = hash(name);
     np->next = hashtab[hashval];
     hashtab[hashval] = np;
  } else

   free((void *) np->defn);

    if ((np->defn = strdup(defn)) == NULL)
     return NULL;
   return np;
  }




int main(){








printf("PRINT --> 0\nADD --> 1 name def\nDEL --> 2 name\nTEXT --> 3 text");



int cmd;
while(scanf("%d",&cmd)) 
  switch(cmd){
     
    case 0:print();break;
    case 1:add();break;
    case 2:del();break;
    case 3:text();break;

  };
      

}

void print(){
 
  for(int i = 0; i < HASHSIZE; i++){
    printf("\n[%d]: ",i); 
    for(struct nlist* p = hashtab[i]; p != NULL; p = p->next)
     printf("[%s %s]",p->name,p->defn);
  };
};

void add(){

 char n[20];
 char d[20];
 scanf("%s %s",&n,&d);
 install(n,d);

};

void del(){

 char n[20];
 scanf("%s",&n);
 struct nlist* p = lookup(n);
 if(p == NULL)return;
 for(int i = 0; i < HASHSIZE; i++)
  if(hashtab[i] == p)
    hashtab[i] = NULL;
 
};

void text(){

  char t[50];
  scanf(" %s",&t);
  printf("t before %s\n",t);
  for(int i = 0; i < HASHSIZE; i++)
   if(hashtab[i] != NULL){
    char* ret = replace(t,hashtab[i]->name,hashtab[i]->defn);
    strcpy(t,ret);
    }

   printf("t after %s\n",t);

}

char *replace(char *orig, char *rep, char *with) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep (the string to remove)
    int len_with; // length of with (the string to replace rep with)
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements

    // sanity checks and initialization
    if (!orig || !rep)
        return NULL;
    len_rep = strlen(rep);
    if (len_rep == 0)
        return NULL; // empty rep causes infinite loop during count
    if (!with)
        with = "";
    len_with = strlen(with);

    // count the number of replacements needed
    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count) {
        ins = tmp + len_rep;
    }

    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

    if (!result)
        return NULL;

    // first time through the loop, all the variable are set correctly
    // from here on,
    //    tmp points to the end of the result string
    //    ins points to the next occurrence of rep in orig
    //    orig points to the remainder of orig after "end of rep"
    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}

 






    


 
 
  

