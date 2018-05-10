//Replace string of blanks with single blank
#include <stdio.h>
#define NON_BLANK 'Y'
int main()
{
	int c;
	int lastc;
	lastc = NON_BLANK;
	while((c=getchar()) != EOF)
	{			
		if(c != ' ' || lastc != ' ')
			putchar(c);
		
		lastc=c;	
	}	
	return 0;
}
