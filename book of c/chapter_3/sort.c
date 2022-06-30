#include <stdio.h>


void print_array(int a[], int n,int x, int y){
	for(int i = 0; i < n; i++)
	 if(i==x || i == y)
	  printf("[%d] ",a[i]);
	   else
	    printf("%d ",a[i]);

  printf("\n");
};
void shellsort(int v[], int n)
{
int gap, i, j, temp;
for (gap = n/2; gap > 0; gap /= 2)
for (i = gap, printf("gap: %d\n",gap); i < n; i++)
for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
temp = v[j];
v[j] = v[j+gap];
v[j+gap] = temp;
print_array(v,n,j,j+gap);
}
}


int main(){

	int x[10] = {10,9,8,7,6,5,4,3,2,1};
        print_array(x,10,-1,-1);
	printf("----------\n");
	shellsort(x,10);


}
