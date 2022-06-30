#include <stdio.h>

  int bin(int x, int v[], int n){
   int low, high, mid;
   low = 0;
   high = n - 1;
    while (low < high) {
     mid = (low+high)/2;
      if (x < v[mid])
       high = mid;
        else if (x > v[mid])
         low = mid + 1;
          else
          /* found match */
           return mid;
    }
       return -1;
       /* no match */
  };


  int bin0(int x, int v[], int n){
  
       int low, high, mid;
       low = 0;
       high = n - 1;
        while( (high>low) && high!=n){
         mid = (low+high)/2;
         if (x < v[mid])
          high = mid;
           else if (x > v[mid])
            low = mid;
             else
              return mid;
        }
          return -1;
 }

  int bin1(int x, int v[], int n){
  
       int low, high, mid;
       low = 0;
       high = n - 1;
        while (low < high) {
         mid = (low+high)/2;

	  if(x!=v[mid]){
            unsigned l =(unsigned)( (mid-x) & -1) >> 31;
	    low = l*(mid+1) + !l*(low);
	    high = !l*(mid) + l*(high);
           }
             else
              return mid;

        }
          return -1;
 }




int main(){

   int x[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

   
   for(int i=0; i<29; i++){
   int z = bin1(i,x,21);
   printf("z_result:%d\n",z);
   };

   printf("done\n"),printf("double"),printf("\n");


};
