#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE *fp;
	int c;
	char input[80];
	int flag;

	if(argc < 3)
	{
		printf("Please try again Input\n");
		return 1;
	}

	if(argv[1] == "0")
	{
		fp = fopen(argv[2], "w");
	}
	else if(argv[1] == "1")
	{
		fp = fopen(argv[2], "a");
	}
	printf("testing\n");
	//scanf("%s", input);
	
	while( scanf(" %*s", input) != 0)
	{
		//printf("test\n");
		//fwrite(fp, "%s\n", input);
		fprintf(fp, "%s", *input);
	}
	fclose(fp);
	return 1;
}
