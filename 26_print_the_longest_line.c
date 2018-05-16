#include <stdio.h>

#define MAXLINE 1000
#define LONGLINE 80

int get_line(char line[], int maxline);
void copy_line(char to[], char from[]);
int string_len(char line[]);

int main()
{
	//Declarations and definitions
	int len = 0;
	int max = 0;
	char line[MAXLINE];
	char longest[MAXLINE];

	//Read a line
	while( (len = get_line(line, MAXLINE)) > 0)
	{
		//If length of line read is greater than max
		if(len > max)
		{
			//Max is equals len
			max = len;
			//Copy line to longest
			copy_line(longest,line);
		}
	}
	//if max is greater than 0 then print the longest line
	if(max > 0)
		printf("\n%s length=%d, max = %d len = %d\n",longest,string_len(longest), max,len);
	return 0;
}

int string_len(char s[])
{
	int i = 0;
	while(s[i++] != '\0');
	return i;
}

int get_line(char s[], int lim)
{
	int c = 0, i = 0;
	//Read a line. One is till limit-1, till EOF and till new line.
	for(i = 0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
	{
		s[i] = c;
	}
	if(c == '\n')
	{
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}

void copy_line(char to[], char from[])
{
	int i;
	i = 0;
	//In a loop cpy character by character till a space	
	while((to[i] = from[i]) != '\0')
		++i;
}

