#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

void Env_empty(void);
void Env_value(char *env);
void Uid(void);
void Gid(void);
void Pid(void);
void PPid(void);

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		perror("Please Re-Enter it in the following format: Command -option ");
		exit(1);
	}
	
	if(strcmp(argv[1], "-e") == 0)	//opt -e
	{
		if(argc > 2)
		{
			Env_value(argv[2]);
		}
		else
		{
			Env_empty();
		}
	}
	
	if(strcmp(argv[1], "-u") == 0)	//opt -u
	{
		Uid();
	}
	
	if(strcmp(argv[1], "-g") == 0)	//opt -g
	{
		Gid();
	}
	
	if(strcmp(argv[1], "-i") == 0)	//opt -i
	{
		Pid();
	}

	if(strcmp(argv[1], "-p") == 0)	//opt -p
	{
		PPid();
	}
}

//option -e
void Env_empty(void)
{
	char **ptr;
	extern char **environ;

	for(ptr = environ; *ptr != 0; ptr++)
	{
		printf("%s \n", *ptr);
	}
	exit(0);
}

//option -e Name
void Env_value(char *env)
{
	char *ptr;

	ptr = getenv(env);
	printf("%s = %s \n", env, ptr);

	exit(0);
}

//option -u
void Uid(void)
{
	printf("My Realistic User ID : %d(%s)\n", getuid(), getpwuid(getuid())->pw_name);
	printf("My Valid User ID : %d(%s)\n", geteuid(), getpwuid(geteuid())->pw_name);

}

//option -g
void Gid(void)
{
	printf("My realistic Group ID : %d(%s)\n", getgid(), getgrgid(getgid())->gr_name);
	printf("My Valid User ID : %d(%s)\n", getegid(), getgrgid(getegid())->gr_name);
	
}

//option -i
void Pid(void)
{
	printf("my process number : [%d]\n", getpid());
}

//option -p
void PPid(void)
{
	printf("my parent's process number : [%d]\n", getppid());
}

