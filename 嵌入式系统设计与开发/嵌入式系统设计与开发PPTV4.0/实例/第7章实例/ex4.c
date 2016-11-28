#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main()
{
	char buf[1];
	int fd1,fd2;
	
	if((fd1=open("hello",O_RDWR))==-1)
	{
		perror("open hello WRONG!");
		exit(1);

	}

	if((fd2=open("hello.backup",O_RDWR|O_CREAT,0644))==-1)
	{
		perror("open hello.backup WRONG!");
		exit(1);

	}

	if(lseek(fd1,0,SEEK_SET)==-1)
	{
		perror("lseek hello WRONG!");
		exit(1);
	}

	while(read(fd1,buf,1)!=0)
	{
		if(write(fd2,buf,1)==-1)
		{
			perror("write hello.backup WRONG!");
			exit(1);
		}
	}
}
