#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char string[32] = "Do you like Linux?";
	char *ptr, *p;
	
	ptr = (char *) malloc(sizeof(string));
	memcpy(ptr, string, strlen(string));
	puts(ptr);
	memset(ptr + 12, 'l', 1);
	puts(ptr);

	p = (char *) memchr(ptr, 'l', 18);	
	puts(p);
	memmove(string + 12, string + 7, 10);
	puts(string);
}
