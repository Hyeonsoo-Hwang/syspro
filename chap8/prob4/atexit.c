#include <stdio.h>
#include <stdlib.h>
static void exit_handler1(void), exit_handler2(void);

int main(void)
{
	if(atexit(exit_handler1) != 0)
	{
		perror("\"exit_handler1\" Unable to register");
	}
	if(atexit(exit_handler2) != 0)
	{
		perror("\"exit_handler2\" Unable to register");
	}
	printf("main Done \n");
	exit(0);
}

static void exit_handler1(void)
{
	printf("First exit Handler\n");
}

static void exit_handler2(void)
{
	printf("Second exit Handler\n");
}
