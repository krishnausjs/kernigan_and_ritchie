//Write a program to print a histogram of the frequencies of different characters in its input


#include <stdio.h>
#include <ctype.h>

#define IN  1
#define OUT 0
#define MAXCHAR 128
#define MAXHIST 15

int main()
{
	//Declarations and initializations
	int c;
	int cc[MAXCHAR];	
	int i,len=0;
	int maxvalue = 0;

	for(i = 0; i < MAXCHAR; i++)
		cc[i]=0;			

	//Read a character and increment the array using it as index
	while( (c = getchar()) != EOF)
	{
		if(c < MAXCHAR)
			++cc[c];
	}	

	//Find the max value
	for(i = 1; i < MAXCHAR; i++)
	{
		if(cc[i] > maxvalue)
			maxvalue = cc[i];
	}

	//Now draw the histogram
	for(i = 1; i < MAXCHAR; ++i)
	{
		//If printable, print it else not.
		if(isprint(i))
			printf("%5d - %c - %5d : ",i, i, cc[i]);
		else
			printf("%5d -    - %5d :", i, cc[i]);

		//only if its greater than 0
		if(cc[i] > 0)
		{
			//scale it by multiplying with a constant and dividing with max value.
			//Const here will be the max length of histogram value.
			len = (cc[i]*MAXHIST/maxvalue);
			if(len <= 0)
				len = 1;
		}
		while(len > 0)
		{
			printf(" * ");
			--len;
		}
		printf("\n");
	}
	
	return 0;
}

