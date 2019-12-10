#include "my.h"
int main()
{
	int pid1,pid2,s1,p1,s2,p2;
	char buff[1024];
	FILE *fp;
	fp=fopen("fork.dat","rt+");
	if((pid1=fork())<0)
	{
		perror("failed to fork\n");
		return -1;
	}else if(pid1==0)
	{
		fputs("child1:0123456789\n",fp);
		exit(0);
	}else{
		if((pid2=fork())<0)
		{
			perror("failed to fork\n");
			return -1;
		}else if(pid2==0)
		{
			fputs("child2:abcdef\n",fp);
			exit(0);
		}else{
			p1=wait(&s1);
			p2=wait(&s2);
			printf("parent is running\n");
			exit(0);

		}

	}
}
