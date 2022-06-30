#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pow(int x, unsigned n) {
   int p, y;
   y = 1;                   
   p = x;                   
   while(1) {
      if (n & 1) y = p*y;   
      n = n >> 1;           
      if (n == 0) return y; 
      p = p*p;              
   }
}



/* atof: convert string s to double */
double atod(char s[]){

 double val, power;
 int i, sign;
 char str_exp[20]; 
 double flt_exp = 1;


  for (i = 0; isspace(s[i]); i++);
   sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
     i++;
      for (val = 0.0; isdigit(s[i]); i++)
       val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
   i++;

 for (power = 1.0; isdigit(s[i]); i++){
  val = 10.0 * val + (s[i] - '0');
  power *= 10;
 }

/* handling e notation */
 if (s[i] == 'e' || s[i] == 'E'){  
  if(s[i+1] == '-'){
    strcpy(str_exp,s+i+2);
    flt_exp = 1/(double)pow(10,atoi(str_exp));
  }else{ 
    strcpy(str_exp,s+i+1);
    flt_exp = pow(10,atoi(str_exp));  
   }
}
 /*                   */
 
  return sign * val / power * flt_exp;
}



int main(int argc, char** argv){

   double f = atod(argv[1]);
   printf("%f\n",f);

}


