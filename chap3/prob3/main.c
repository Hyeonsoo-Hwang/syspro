#include <stdio.h>
#include "copy.h"
#include <string.h>

char line[MAXLINE];	//input line
char longest[MAXLINE];	//output line
void copy(char from[], char to[]);

int main()
{
	int len;
	int max;
	max = 0;

	while(fgets(line,MAXLINE,stdin) != NULL)
	{
		len = strlen(line);

		if(len > max)
		{
			max = len;
			copy(line, longest);
		}
	}

	if(max > 0)
	{
		printf("%s", longest);
	}
	return 0;
}

