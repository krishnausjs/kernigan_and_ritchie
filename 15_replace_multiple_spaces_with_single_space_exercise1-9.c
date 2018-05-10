//Counter characters
#include <stdio.h>
#define NON_BLANK 'x'
int main()
{
	double blanks=0;
	
	int c;
	int lastc;
	
	while((c=getchar()) == ' ')
		 		;
	putchar(c);
	
	lastc = NON_BLANK;
	while((c=getchar()) != EOF)
	{
		if(c != ' ')
		{
			putchar(c);
		}
		
		if(c == ' ') 
		{
			if(lastc != ' ')
				putchar(c);
		}	
		lastc = c;
	}
	
	return 0;
}
