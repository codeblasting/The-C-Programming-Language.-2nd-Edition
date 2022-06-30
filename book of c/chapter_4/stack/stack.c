#include "stack.h"

/* maximum depth of val stack */
/* next free stack position */
/* value stack */
/* push: push f onto value stack */
void push(double f){
 if (sp < MAXVAL)
 val[sp++] = f;
 else
  printf("error: stack full, can't push %g\n", f);
 }
 /* pop: pop and return top value from stack */
 double pop(void){
  if (sp > 0)
   return val[--sp];
  else {
   printf("error: stack empty\n");
   return 0.0;
  }
 }






/* getop: get next character or numeric operand */
int getop(char s[])
{
static int last_c = ' ';

int i=0, c;

if(last_c != EOF){ c = last_c; last_c = ' '; }
 
  

while ((s[0] = c ) == ' ' || c == '\t')
     c = getch();//skip spaces and tabs

//printf("s[0] %c\n",s[0]);


if(c=='v'){
  while( (s[i++] = getch()) != '\n' );
  s[i-1] = '\0';
  return VAR_ADD;
};

if(c=='g'){ 
 s[0] = getch();
 s[1] = '\0';
 return VAR_PRINT;
};

if(c=='r'){
 s[0] = getch();
 return VAR_REM; 
};

//int x = get_variable(c,&c,0);
// Kodel luzta nuo sito call? stack smashing detected
// valgrind --leak-check=full ./a.out [ read from bad addr ]
 
if (!isdigit(c) && c != '.' && c!= '-'){

s[1] = '\0';
return c;
};

if (c=='-'){
c = getch();
if( isdigit(c) || c=='.' ){
  i=1;
  s[i] = c;
}else {ungetch(c); s[1] ='\0'; return '-';}
};

if (isdigit(c))
/* collect integer part */
while (isdigit(s[++i] = c = getch()))
;
if (c == '.')
/* collect fraction part */
while (isdigit(s[++i] = c = getch()))
;
s[i] = '\0';

last_c = c;
return NUMBER;
}

void print_stack(){
  
  if(sp == 0){
     printf("stack is empty!\n");
     return;
   };
  for(int i = sp-1; i >= 0 ; i--)
    printf("%d: %f\n",i,val[i]);
};


void duplicate(int n){

   if( (sp+n) > MAXVAL ){
     printf("cannot duplicate!\n");
     return;
   };

  for(int i = sp - n,target = sp; i < target; i++)
   push(val[i]);
    printf("duplicated\n");
};

void swap_two(){

   if(sp<2){
     printf("did not swap!\n");
     return;
   }
      double temp = val[sp-1];
      val[sp-1] = val[sp-2];
      val[sp-2] = temp;
      printf("swap was OK\n");
      
};

void clear_stack(){
 if(sp==0){
   printf("already clean!\n");
   return;
 };

  sp = 0;
  val[sp] = 0;
   printf("cleared\n");
};


void stack_loop(){

 int type;
   double op2;
   char s[MAXOP];
    while ((type = getop(s)) != EOF) {
     switch (type){
      case NUMBER:
       push(atof(s));
        break;
      case '+':
       push(pop() + pop());
        break;
      case '*':
       push(pop() * pop());
        break;
      case '-':
       op2 = pop();
       push(pop() - op2);
        break;
      case '/':
       op2 = pop();
        if (op2 != 0.0)
         push(pop() / op2);
        else
        printf("error: zero divisor\n");
	break;
      case '%':
       op2 = pop();
        if (op2 != 0.0)
         push((int)pop() % (int)op2);
        else
        printf("error: zero divisor\n");
         break;
      case 'c':
	clear_stack();
	getch();
	break;
      case 's':
	 swap_two();
	 getch();
	 break;
      case 'p':
	 print_stack();
	 getch();
	 break;
      case 'd':
	 duplicate(1);
	 getch();
	 break;
      case 'E':
         push(exp(pop()));
	 break;
      case 'S':
         push(sin(pop()));
	 break;
      case 'P':
         push(pow(pop(),pop()));
         break;
      case VAR_ADD: 
         add_variable(s);	
         break;
      case VAR_PRINT:
          if( get_variable(s[0],&op2,0)==0 )
           if(s[0] == 'l')
	    printf("last = %f\n",op2);
	     else
	      printf("%c = %f\n",s[0],op2);
	  getch();	  
	   break;
      case VAR_REM:
	  remove_variable(s[0]);
	  getch();
	   break;
      
      case ':':
	 ungets(s);
	 break;
      case ',':
	 push(val[sp-1]);
	 break;
     case ';':
      case '\n':
        printf("\t%.8g\n",val[sp-1]);
         break;
 default:
  if( get_variable(s[0],&op2,0)==0 )
    push(op2);
     else
      printf("error: unknown command %s\n", s);
 break;
     }
   }
return;
}


