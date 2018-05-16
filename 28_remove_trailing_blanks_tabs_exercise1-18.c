#include <stdio.h> 

#define LINE_LENGTH 1000
#define MAX_LINE_LENGTH 80

//TODO: Need to revisit and check why the for loop below doesnt work
#if 0
int get_line(char line[],int lim)
{
	int c, i;

	for(i = 0; ((i < lim-1) && (c = getchar() != EOF) && (c != '\n')); ++i)
	{
		printf("in loop %d\n",i);
		line[i]=c;
	}
	printf("out loop %d\n",i);
	if(c == '\n')
		line[i] = c;

	i++;

	printf("out loop two - %d\n",i);
	line[i] = '\0';
	return i;
}
#else

int get_line(char line[],int lim)
{
	int c;
	int lc = 0;
	while((lc < lim-1) && ((c = getchar()) != EOF) && (c != '\n'))
	{
		line[lc++]=c;
	}
	
	if(c == '\n')
		line[lc] = c;

	lc++;

	line[lc]='\0';
	return lc;
}
#endif


int main()
{
	int len = 0;
	char line[LINE_LENGTH];
	
	if((len = get_line(line,MAX_LINE_LENGTH)) > 0)	
	{ 
		printf("%s ",line);
	}
	printf("\nValue of len is %d\n",len);
	return 0;
}
