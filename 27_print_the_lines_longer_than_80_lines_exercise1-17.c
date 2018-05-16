#include <stdio.h> 

#define LINE_LENGTH 1000
#define MAX_LINE_LENGTH 80

int get_line(char line[])
{
	int c;
	int lc = 0;
	while(((c = getchar()) != EOF) && (c != '\n'))
	{
		line[lc++]=c;
	}
	if(c == '\n')
		line[lc] = c;

	lc++;

	line[lc]='\0';
	return lc;
}


int main()
{
	int i;
	int c;
	int len = 0;
	char line[LINE_LENGTH] = {0};
	
	if((len = get_line(line))>0)	
	{
		printf("%s\n",line);
	}
		printf("Value of len is %d\n",len);
	return 0;
}
