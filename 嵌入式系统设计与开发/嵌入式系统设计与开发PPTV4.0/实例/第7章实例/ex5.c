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
	
	if(read(STDIN_FILENO,buf,1)==-1)
	{
		perror("read STDIN WRONG!");
		exit(1);
	}
	
	if(write(STDOUT_FILENO,buf,1)==-1)
	{
		perror("write STDOUT WRONG!");
		exit(1);
	}
}
