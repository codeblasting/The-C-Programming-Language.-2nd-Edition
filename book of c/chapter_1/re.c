#include <stdio.h>


main()
{

	int c;
	char str[999];
	int i = 0;
	while( (c = getchar()) != EOF)
	     str[i++] = c;

	for(int k = 0; k < i/2; k++)
	 {
		 int temp = str[k];
		 str[k] = str[i-2-k];
		 str[i-2-k] = temp;
	 }

	printf("%s",str);
}
