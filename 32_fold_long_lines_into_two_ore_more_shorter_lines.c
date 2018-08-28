//Write a program to fold long input lines into two or more shorter lines after the last non-blank character that occurs before the nth column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.

#include <stdio.h>

#define MAXCOL 10  //Maximum column of input
#define TABINC 8   //Tab increment size

char line[MAXCOL]; //Input line

int exptab(int pos);
int findblnk(int pos);
int newpos(int pos);
void printl(int pos);

//Fold long input lines into two or more shorter lines
int main()
{
	int c, pos;
	
	pos = 0;					//Position in the line
	while( (c = getchar()) != EOF)
	{
		line[pos] = c;			//Store current character
		if ( c == '\t' )       //Expand tab character
			pos = exptab(pos);
		else if (c == '\n')
		{
			printl(pos);     //Print current input line
			pos = 0;
		}
		else if( ++pos >= MAXCOL )
		{
			pos = findblnk(pos);
			printl(pos);	
			pos = newpos(pos);
		}
	}
}

//Printl: Print line untill pos column
void printl(int pos)
{
	int i;
	for(i = 0; i < pos; ++i)
		putchar(line[i]);
	if( pos > 0)		//Any characters are printed ?
		putchar('\n');	
}
