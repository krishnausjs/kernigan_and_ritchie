//Write a program to print a histogram of the lenghts of words in its input.
//It is easy to draw the histogram with the bars horizontal; a vertical orientation is
//more challenging.

#include <stdio.h>

#define MAXHIST 15 //Max length of histogram
#define MAXWORD 11 //Max length of a word
#define IN 1       //Inside word
#define OUT 0      //Outside word

#ifdef DEBUG_ENABLE
#define MMK_PRINTF(f_, ...) printf((f_), ##__VA_ARGS__)
#else
#define MMK_PRINTF(f_, ...) 
#endif

int main()
{
	int i,c,state,maxvalue,nc;
	int wl[MAXWORD]={0},ovflow,len;

	for(i = 0; i < MAXWORD; ++i)
			wl[i] = 0;                    // Reset all words to 0

	state = OUT;
	nc = 0;       //Number of chars in a word
	ovflow = 0;   //Number of words >= MAXWORD		

	while((c = getchar()) != EOF)  //Keep on reading the char till end of the file ctrl+D.
	{
		if(c == ' ' || c == '\n' || c == '\t') //check of whites.
		{
			state = OUT; //if whites we just completed a word.
			if(nc > 0)   //For number of characters greater than 0. Avoid white spaces in the beginning.
				if(nc < MAXWORD)    //If they are under maxword increment word length counter
				{
					MMK_PRINTF("\nValue of nc is %d\n",nc);
					++wl[nc];
				}
				else
				{
					++ovflow;
				}
			nc = 0;
		}
		else if(state == OUT) 
		{
			state = IN; //Turn state to in as we are into a new word.
			nc = 1;    //Beginning of a new word
		}
		else	
		{
			//printf("\nIncrementing nc  %d\n",nc);
			++nc; 		//Inside a word
		}
	}

	maxvalue = 0; //initialize maxvale.
	MMK_PRINTF("Printing wl values\n");
	for(i = 0; i < MAXWORD; ++i)
		MMK_PRINTF("  %d\t",wl[i]);
	putchar('\n');

	MMK_PRINTF("Finding maxvalue in wl values\n");
	for(i = 0; i < MAXWORD; ++i)
		if(wl[i] > maxvalue)    //for each wl value, compare it with maxvalue (which is 0 by default). if wl is more, then update maxvalue with it.
			maxvalue = wl[i];

	MMK_PRINTF("Maxvalue is %d\n",maxvalue);

	//Now its time to print histogram.
	for(i = 1; i < MAXWORD; ++i)
	{
		//for each i , print the histogram using wl values. 
		printf("%5d - %5d : ",i,wl[i]);
		if(wl[i] > 0) //For each wl which is greater than 0.
		{
            len = (wl[i] * MAXHIST / maxvalue);  // Scaling wl according to MAXHIST and maxvalue.
			MMK_PRINTF("wl[%d] = %d, maxvalue = %d, len = %d\n",i,wl[i],maxvalue,len);
			if(len <= 0)
				len = 1;
		}
		else
			len = 0;
		MMK_PRINTF("Value of len = %d\n",len);
		while(len > 0)
		{
			putchar('*');
			--len;
		}
		putchar('\n');
	}

	if(ovflow > 0)
			printf("There are %d words >= %d \n", ovflow, MAXWORD);
	return 0;
}
