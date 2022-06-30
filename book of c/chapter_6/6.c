#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD 100


struct tnode {
char *word;
int count;
struct tnode *left;
struct tnode *right;
};

char *str_dup(char *);
struct tnode *t_alloc();
struct tnode *add_tree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
int the_count;

/* word frequency count */
main(int argc, char** argv)
{

the_count = argc == 2 ? atoi(argv[1]) : 3;

struct tnode *root;
char word[MAXWORD];
root = NULL;
while (getword(word, MAXWORD) != EOF)
if (isalpha(word[0]))
root = add_tree(root, word);
treeprint(root);
return 0;
}

char *str_dup(char *s)
{
char *p;
/* make a duplicate of s */
p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
if (p != NULL)
strcpy(p, s);
return p;
}

/* talloc: make a tnode */
struct tnode *t_alloc()
{
return (struct tnode *) malloc(sizeof(struct tnode));
}


/* addtree: add a node with w, at or below p */
struct tnode *add_tree(struct tnode *p, char *w)
{
int cond;
if (p == NULL) {
/* a new word has arrived */
p = t_alloc();
/* make a new node */
p->word = str_dup(w);
p->count = 1;
p->left = p->right = NULL;
} else if ((cond = strncmp(w, p->word,the_count)) == 0)
p->count++;
/* repeated word */
else if (cond < 0)
/* less than into left subtree */
p->left = add_tree(p->left, w);

else
/* greater than into right subtree */
p->right = add_tree(p->right, w);
return p;
}



/* getword: get next word or character from input */
int getword(char *word, int lim)
{
int c, getch(void);
void ungetch(int);
char *w = word;

   while (isspace(c = getch()));

   if(c=='\"'){
   while( (c=getch()) != '\"');
   c=getch();
   };

   if(c=='\\'){
   while( (c=getch()) != '\n');
   c=getch();
   };


if (c != EOF)
*w++ = c;
if (!isgraph(c)) {
*w = '\0';
return c;
}
for ( ; --lim > 0; w++)
if (!isgraph(*w = getch())) {
ungetch(*w);
break;
}
*w = '\0';

return word[0];
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
if (p != NULL) {
treeprint(p->left);
printf("%4d %s\n", p->count, p->word);
treeprint(p->right);
}
}






