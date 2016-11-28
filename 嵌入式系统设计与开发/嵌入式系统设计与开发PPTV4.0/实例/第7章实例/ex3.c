#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define READ_SIZE 10
void main()
{
	char r_buf[READ_SIZE];
	int filedes;
	
	if((filedes=open("hello",O_RDWR))==-1)
	{
		perror("open hello WRONG!");
		exit(1);

	}
	if(lseek(filedes,20,SEEK_SET)==-1)
	{
		perror("lseek WRONG!");
		exit(1);
	}
	if(read(filedes,r_buf,10)==-1)
	{
		perror("read hello WRONG!");
		exit(1);	
	}
	else
	printf("%s\n",r_buf);
}
