#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"
/* 학번을 입력받아 해당 학생 레코드를 수정한다. */
int main(int argc, char *argv[])
{
   	int fd, id;
   	char c;
   	struct student record;
   	if (argc < 2)
	{
      		fprintf(stderr, "How to use : %s file\n", argv[0]);
      		exit(1);
   	}
   	if ((fd = open(argv[1], O_RDWR)) == -1)
	{
      		perror(argv[1]);
      		exit(2);
   	}
   	do
	{
      		printf("Enter StudentID to be modified: ");
      		if (scanf("%d", &id) == 1)
		{
         		lseek(fd, (long)(id-START_ID) * sizeof(record), SEEK_SET);
         		if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0))
			{
            			printf("StuID:%8d\t Name:%4s\t Score:%4d\n", record.id, record.name, record.score);
				printf("New Score: ");
            			scanf("%d", &record.score);
            			lseek(fd, (long) -sizeof(record), SEEK_CUR);
            			write(fd, (char *) &record, sizeof(record));
         		} 
			else
			{	
				printf("Record %d Null\n", id);
			}
      		} 
		else 
		{
			printf("Insert Error\n");
		}
      		printf("Continue?(Y/N)");
      		scanf(" %c",&c);
   	} while (c == 'Y');
   	
	close(fd);
   	exit(0);
}

