
#include "globals.h"
#include "getch.h"

char variables[200];
// g 2\n h 4\n
char* reserved;




/* buffer for ungetch */
/* next free position in buf */

void add_variable(char* s);
void remove_variable(char c);
int get_variable(char c, double* f,int silent );
int get_index(char c, char* s);
void delete_line(char c, char* s1);
void copy_line(char* s0, char* s1);




void ungets(char *s);
