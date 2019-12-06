#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

char buf[]={"write to stdout \n"};
int main ()
{
	pid_t pid;
	freopen("test1.txt","w",stdout);
	if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
		perror("can't write\n");
	//printf("printf\n");
	printf("printf");
	pid=fork();
	if(pid<0)
	{
		perror("fork error \n");
	}
	exit(0);
}
