#include <stdio.h>

#define MAXHIST 15
#define MAXWORD 11
#define IN      1
#define OUT     0

#define DEBUG_ENABLED 1

#ifdef DEBUG_ENABLED
#define MMK_PRINTF(f_, ...) printf((f_), ##__VA_ARGS__)
#else
#define printf((f_), ...)
#endif


int main()
{
	//Define and initialize variables.
	int c, i, j, nc, state;
	int maxvalue;
	int ovflow;
	int wl[MAXWORD];
	int len = 0;

	state = OUT;
	nc = 0;
	ovflow = 0;

	for(i = 0; i < MAXWORD; ++i)
		wl[i] = 0;

	//Inspect every character input
	while((c = getchar()) != EOF)
	{
		//Look for whites
		if(c == ' ' || c == '\n' || c == '\t')
		{
			//If we are here then we have completed parsing a word except for the first time
			state = OUT;
			
			//Make sure we have parsed the word. If its a white space before the input, discardit.
			if(nc > 0)
				if(nc < MAXWORD)
					++wl[nc];
				else 	
					++ovflow;
			nc = 0;
		}
		else if(state == OUT)
		{
			//Good we hit a word to parse. Count it now.
			state = IN;
			nc = 1;
		}
		else
		{
			//We are parsing the word
			++nc;
		}
	}

	maxvalue = 0;

	printf("Current wl values are \n");
	for(i = 0; i < MAXWORD; ++i)
		printf("%d ",wl[i]);

	//Same drill continues. We update maxvalue to the max in array.
	for(i = 0; i < MAXWORD; ++i)
		if(wl[i] > maxvalue)
			maxvalue = wl[i];
	
	printf("\n");
	//Here comes the different part compard to earlier program 20*.c
	//We print rows and columns.
	for(i = MAXHIST; i > 0; --i) 
	{
		printf("%2d ",i);
		//For word lenth
		for(j = 1; j < MAXWORD; ++j)
		{
			len = wl[j] * MAXWORD / maxvalue;
			//Scale wl values as per MAXHIST and maxvalue
			if(len >= i)
				printf(" * ");
			else
				printf("   ");
		}
		putchar('\n');
	}
	printf("   ");
	for(i = 1; i < MAXWORD; ++i)
		printf("%2d ",i);
	putchar('\n');

	if(ovflow > 0)
		printf("There are %d words >= %d\n", ovflow, MAXWORD);
}
