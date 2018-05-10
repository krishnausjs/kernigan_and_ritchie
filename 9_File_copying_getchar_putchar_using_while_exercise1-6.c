//Verify that the expression getchar() != EOF is 0 or 1
#include <stdio.h>
int main()
{
	int c;
    if(c=(getchar() != EOF))
	{
		printf("Expression is 1\n");
    }
    else
    {
    	printf("Expression is 0\n");
	}
	return 0;
}
