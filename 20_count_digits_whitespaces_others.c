//Program to count digits, white spaces and others
#include <stdio.h>

int main()
{
	int i,c;
	int ndigits[10]={0};
	int nwhites = 0, nothers = 0;

	for(i = 0; i < 10; ++i)
	{
		ndigits[i]=0;
	}	

	while((c=getchar()) != EOF)
	{
		if(c >= '0' && c <= '9')
		{
			++ndigits[c-'0'];
		}
		else if( c == ' ' || c == '\t' || c == '\n')
		{
			++nwhites;
		}
		else
			++nothers;
	}
	printf("Digits =");
	for(i = 0; i < 10; ++i)
		printf("%d ",ndigits[i]);
	printf(" , White spaces = %d , other = %d\n",nwhites, nothers);	
	return 0;
}
