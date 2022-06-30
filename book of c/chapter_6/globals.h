#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <math.h>
#include <string.h>





#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 15 
#define BUFSIZE 100

#define VAR_ADD '1'
#define VAR_PRINT '2'
#define VAR_REM '3'
#define VAR_GET '4'


int sp;
int bufp;

double val[MAXVAL];
char buf[BUFSIZE];


