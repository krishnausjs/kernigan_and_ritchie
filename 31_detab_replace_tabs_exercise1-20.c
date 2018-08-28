//Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops,say every n columns. Should n be a variable or a symbolic parameter.

#include <stdio.h>

#define TABINC 8 /*Tab increment size */

/* Replace strings of blanks with tabs and blanks */
int main()
{
	int c, nb, nt, pos;
	
	nb = 0;  // # of blanks necessary
	nt = 0;  // # of tabs necessary
	
	for(pos = 1; (c = getchar()) != EOF; ++pos)
	{
		//Replace string of blanks by the minimum number of tabs and blanks to achieve the same spacing
		if(c == ' ')
		{
			if(pos % TABINC != 0)          //8 spaces =  1 tab.  
				++nb;                      //Increment # of blanks
			else
			{
				nb = 0;						//Reset number of blanks
				++nt;						//One more tab
			}
		}
		else
		{
			for( ;nt > 0; --nt)
				putchar('\t');				//Output tabs
			if(c == '\t')					//Forget the blanks
				nb = 0;
			else							//Output blanks
				for( ; nb > 0; --nb)
					putchar(' ');

			putchar(c);
			if( c == '\n' )
				pos = 0;		
			else if( c == '\t' )
					pos = pos + (TABINC - (pos - 1) % TABINC) - 1;
		}
	}
	return 0;
}
