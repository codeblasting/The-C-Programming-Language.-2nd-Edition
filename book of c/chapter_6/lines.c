#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "getch.h"
#define MAX 75


struct WORD{
 char lines[30]; 
 char word[30];
 int  count;
 } words[30];



int lines = 1;
int length = 0;

 int get_word(char*);
 void add_word(char*, int );
 void q_sort(struct WORD[], int, int);
 void swap(struct WORD v[], int i, int j);

 int main(){

  char w[MAX];

int l;
while( l = get_word(w) )
  add_word(w,l);

  q_sort(words,0,29);
  


  for(int i = 0; i < length; i++)
   printf("word %s count %d lines %s\n",words[i].word,words[i].count,words[i].lines);
  
 };


//finds n/ if word returns lin


 int get_word(char* word){

  int line = lines;  

  int index = 0;
  char* p = word;
  char c = getch();

    while(c == ' ')
     c = getch();

    while(c != ' ' && c != EOF)
      if(c == '\n'){
       lines++;
       return line;
       break;
      }else{
	*p++ = c;
         c = getch();
       };	 

    *p = '\0';
   
    return (word[0] != '\0') ? line : 0;
         

}

void add_word(char* arg_str, int lines){

	for(int i = 0; i < length;i++)
	 if(strcmp(arg_str,words[i].word) == 0){
	   words[i].count++;
	   sprintf(words[i].lines+strlen(words[i].lines)," %d",lines);
	   return;
	 };

	words[length].count = 1;
	strcpy(words[length].word,arg_str);
	sprintf(words[length].lines," %d",lines);
	length++;

};


/* swap: interchange v[i] and v[j] */
void swap(struct WORD v[], int i, int j)
{
struct WORD temp;
temp = v[i];
v[i] = v[j];
v[j] = temp;
}


void q_sort(struct WORD v[], int left, int right)
{
int i, last;
if (left >= right) /* do nothing if array contains */
return;
/* fewer than two elements */
swap(v, left, (left + right)/2);
last = left;

for (i = left+1; i <= right; i++)
if (v[i].count > v[left].count)
swap(v, ++last, i);
swap(v, left, last);
q_sort(v, left, last-1);
q_sort(v, last+1, right);
}





     
   
 
   
    
    
    

    

     
        

  







