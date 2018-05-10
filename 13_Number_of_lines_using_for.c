//Counter characters
#include <stdio.h>
int main()
{
	double nc;
	int c;
	for(nc=0; (c=getchar()) != EOF; )
		if(c == '\n')
			++nc;
   	printf("Number of lines13 are %.0f\n",nc);
	return 0;
}
