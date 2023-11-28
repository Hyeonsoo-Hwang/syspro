#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("My process Number : [%d] \n", getpid());
	printf("My parent process Number : [%d] \n", getppid());
}
