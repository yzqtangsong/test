#include "my.h"

int main()
{
	int n=0;
	int temp;
	pid_t r;
	int r_num;
	int pipefd[2];
	char buf[4096];
	memset(buf,0,sizeof(buf));
	if(pipe(pipefd)<0)
	{
		perror("pipe failed.\n");
		return -1;
	}
	r= fork();
	if(r<0)
	{
		perror("fork failed.\n");
		return -1;

	}else if(r==0)
	{
		sleep(5);
		temp=getppid();
	 	wait(&temp);
		close(pipefd[1]);
		
		if((r_num=read(pipefd[0],buf,100))>0)
			printf("child read form pipe :%s ,total =%d\n",buf,r_num);
		close(pipefd[0]);
		sleep(5);
		exit(0);
	}
	else {
	
	close(pipefd[0]);
	while(write(pipefd[1],"1",1)!=-1)
	{
		n++;
		printf("n=%d;\n",n);
	}
	printf("parent write ok\n");
	close(pipefd[1]);
	return 0;
	

}

}
