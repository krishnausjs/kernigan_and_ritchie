//Count number of lines, words and characters in input
#include <stdio.h>

#define IN  1
#define OUT 0
int main()
{
	int c, nc = 0, nw = 0, nl = 0;
	int state = OUT;
	
	while((c=getchar()) != EOF)
	{
		++nc;
		if(c == '\n')
			++nl;
			
		if(c == ' ' || c == '\n' || c == '\t' )
		{
		    state = OUT;
		}	
		else if(state == OUT)
		{
			state = IN;
			++nw;
		}
	}	
	printf("nl=%d nw=%d nc=%d\n",nl, nw, nc);
	return 0;
}
