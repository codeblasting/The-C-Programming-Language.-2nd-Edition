#include <stdio.h>
#include <string.h>

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


int main(){

	char str[10];
	int result = 0;
	int current_power = 0;
	scanf("%s",str);
         
	 if(str[0]!='0' && str[1]!='x' && str[1]!='X')
	  return -1;

	 for(int i = strlen(str)-1; i!=1; i--){
           
		 int current = 0;
		 if(str[i] >= 'A' && str[i] <= 'F')
			 current = str[i] - 55;
		   else
		    if(str[i] >= 'a' && str[i] <= 'f')
			    current = str[i] - 87;
		      else
		       if(str[i] >= '0' && str[i] <= '9')
			       current = str[i] - 48;
		         else
	                  return -1; 

	      result += current*pow(16,current_power++);
	 };

	 printf("result: %d\n", result);

       return 0;
};
