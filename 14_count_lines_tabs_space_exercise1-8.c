//Counter characters
#include <stdio.h>
int main()
{
	double blanks=0;
	double tabs=0;
	double nl=0;
	
	int c;
	while((c=getchar()) != EOF)
	{
		if(c == ' ')
			++blanks;
		else if( c == '\t')
		{
			++tabs;
		} 
		else if( c == '\n')
		{
			++nl;			
		}		
	}
	printf("Number of blanks = %.0f , tabs = %.0f, num of lines = %.0f\n",blanks,tabs,nl);
	
	return 0;
}
