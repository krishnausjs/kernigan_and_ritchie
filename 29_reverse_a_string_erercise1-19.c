//Write a function reverse(s) that reverse the character string s. Use it to write program
//that reverses its input a line at a time.
#include <stdio.h>

#define MAX_LINE_LENGTH 1000
#define LINE_BUF 100

int get_line(char s[], int lim)
{
	int cc=0;
	int c;

	while((cc < lim-1) && ((c = getchar()) != EOF) && (c != '\n'))
	{
		s[cc++] = c;
	}

	if(c == '\n')
		s[cc] = c;
		
	cc++;
	s[cc] = '\0';
	return cc;
}


int reverse(char s[])
{
	int i = 0, j = 0;
	char temp;

	while(s[i] != '\0') // Find the end of strings
		i++;

	--i;	//back off from '\0'
	
	if(s[i] == '\n')
		--i;            //Leave new line in place

	j = 0;
	
	while(j < i) 
	{
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		++j;
		--i;
	}
	return 0;
}

int main()
{
	char s[MAX_LINE_LENGTH] = {0};
	int len = 0;

	if((len = get_line(s,MAX_LINE_LENGTH) > 0))
	{
		printf("Actual : %s\n",s);
		reverse(s);
		printf("Reverse: %s\n",s);
	}
	return 0;
}
