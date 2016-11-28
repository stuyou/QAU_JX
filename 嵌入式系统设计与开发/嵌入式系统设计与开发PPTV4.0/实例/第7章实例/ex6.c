#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 10
void main()
{
	char head_buf[SIZE]="aaaaaaaaaa";
	char tail_buf[SIZE]="AAAAAAAAAA";
	char c[1]="a";
	int n=1;
	int fd1,fd2;
	

	if((fd1=open("file.hole",O_RDWR|O_CREAT,0644))==-1)
	{
		perror("open file.hole WRONG");
		exit(1);
	}
	if((fd2=open("file.nohole",O_RDWR|O_CREAT,0644))==-1)
	{
		perror("open file.nohole WRONG");
		exit(1);
	}
	
	if(write(fd1,head_buf,10)==-1)
	{
		perror("write file.nohole WRONG");
		exit(1);
	}

	if(lseek(fd1,16384,SEEK_SET)==-1)
	{
		perror("lseek file.nohole WRONG");
		exit(1);
	}

	if(write(fd1,tail_buf,10)==-1)
	{
		perror("write file.nohole WRONG");
		exit(1);
	}

	while(n<=16394)
	{
		if(write(fd2,c,1)==-1)
		{
			perror("write file.nohole WRONG");
			exit(1);
		}
		n++;
	}
}
