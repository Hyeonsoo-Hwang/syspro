#include <stdio.h>
#include "copy.h"
#include <string.h>

#define MAX_LENGTH MAXLINE

char sentences[5][MAX_LENGTH];

void sort(char (*string)[MAX_LENGTH]);

int main()
{
	int i = 0;
	while((fgets(sentences[i],MAX_LENGTH,stdin) != NULL) && i < 4)
	{
		++i;
	}

	sort(sentences);

	for(i = 0; i < 5; i++)
	{
		printf("%s", sentences[i]);
	}
	return 0;
}

void sort(char (*string)[MAX_LENGTH])
{
	char temp[MAX_LENGTH];
	int i, j;

	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5 - i - 1; j++)
		{
			if(strlen(string[j]) < strlen(string[j+1]))
			{
				strcpy(temp, string[j]);
				strcpy(string[j], string[j+1]);
				strcpy(string[j+1], temp);
			}
		}
	}
}
