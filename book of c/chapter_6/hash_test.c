#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct NODE{
  struct NODE* next;
  int value;
  char text[20];
};

struct NODE* nodes[10];

struct NODE* get_key(int val){

   for(struct NODE* p = nodes[val % 10]; p != NULL; p = p->next)
    if(p->value == val)
     return p;

   return NULL;
}

void insert(int val,char* c){

 
    struct NODE* np = malloc(sizeof(struct NODE));
           np->value = val;
           strcpy(np->text,c);

     int hash = val % 10;  
     np->next = nodes[hash];
     nodes[hash] = np;
         
  
    

}

void print(){
  
 for(int i = 0; i < 10; i++){
  printf("\nvalues for %d: ",i);
  for(struct NODE* p = nodes[i]; p != NULL; p = p->next)
   printf(" [%d %s] ",p->value,p->text);
 }

}

void delete(int val){
   
  nodes[val % 10] = NULL;
   
};
 


main(){

int d; 
char c[30];
do{

 scanf("%d",&d);
 scanf("%s",&c);
 insert(d,c);

}while(d!=-1);


struct NODE* p = get_key(1);

printf("key of val 1 is %s\n",p->text);

print();





};
