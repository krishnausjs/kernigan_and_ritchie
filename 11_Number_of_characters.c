//Counter characters
#include <stdio.h>
int main()
{
	int c;
	int nc;
	while((c=getchar()) != EOF)
		++nc;
   	printf("Number of characters are %d\n",nc);
	return 0;
}
