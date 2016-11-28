#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main()
{
	char w_buf[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int filedes;
	
	if((filedes=open("hello",O_RDWR|O_CREAT,0644))==-1)
	{
		perror("open hello WRONG!");
		exit(1);
	}
	if(write(filedes,w_buf,26)==-1)
	{
		perror("write hello WRONG!");
		exit(1);	
	}
}
