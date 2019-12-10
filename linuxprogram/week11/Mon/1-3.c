#include "my.h"
int main()
{
	int pid,s;
	if(pid=fork()<0)
	{
		perror("failde to fork\n");
		return -1;
	}else if(pid ==0)
	{
		printf("%d:child is running!\n",getpid());
		printf("%d:child is exit now!\n",getpid());
		while(1);
		exit(120);	

	}else{
		printf("%d:parent is waiting zomble now \n",getpid());
		while(pid=wait(&s)!=-1)
		{
			printf("parent is exiting now \n");
			if(WIFEXITED(s)){
				printf("child %d is exitint now,exit code=%d\n",pid,WTERMSIG(s));
			
			}else if(WIFSIGNALED(s)){
				printf("child %d exit by signal.signal no =%d\n",pid,WTERMSIG(s));
			}else{
				printf("Not konw!\n");			

			}
		}

	}
	exit(0);
}
