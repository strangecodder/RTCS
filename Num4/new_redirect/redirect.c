#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
//int argc;
//char *argv[2];

// execvp - 

int main (int argc,char *argv[])
{
	int fd; 
	fd = open(argv[1],O_CREAT|O_WRONLY|O_TRUNC,0666);
	dup2(fd,1);
	close(fd);
    int length = strlen(argv);
    for(int i = 0 ;i<length-2;i++){
        execvp( argv[i+1], &argv[i+1]); 
    }
	perror("main");
} 