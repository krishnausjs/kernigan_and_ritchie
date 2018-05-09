#include <stdio.h>
int main()
{
	int c = getchar(); // We cannot use char since c must be big enough to hold EOF in addition to any possible char. So, we use int.
	while(c != EOF)
	{
		putchar(c);
		c = getchar();
	}
	return 0;
}
