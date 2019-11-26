#include "my.h"
int count=0;
int main()
{
	int s1,s2,s3,r1,r2,r3;
	pid_t p1,p2,p3;
	int r_num;
	int pipefd[2];
	char buf[4096];
	int temp[4096];
	memset(buf,0,sizeof(buf));
	if(pipe(pipefd)<0)
	{
		perror("pipe failed\n");
	}
	p1=fork();
	if(p1<0)
	{
		printf("p1 failed to fork");	
		return -1;
	}else if(p1==0)
	{	
		count=+1;
		close(pipefd[0]);
		if(write(pipefd[1],"1234567890",10)!=-1)
		{
			printf("child1 write.\n");
		}
		close(pipefd[1]);
		exit(99);
	}else
	{
		printf("parten fork second.\n");
		p2=fork();
		if(p2<0)
		{
			printf("p2 failed to fork");	
			return -1;
		}else if(p2==0)
		{
			count+=1;
			printf("child p2 pid =%d,ppid =%d,count=%d\n",getpid(),getppid(),count);
			close(pipefd[1]);
			if(r_num=read(pipefd[0],buf,100)>0)
			{
				printf("child2 read from pipe :%s,total=%d\n",buf,r_num);
			}
			int i=0;
			while(i<10)
			{
				temp[i]=atoi(&buf[i]);
				printf("temp[%d] = %d\n",i,temp[i]);
				i++;
			}
			close(pipefd[0]);
			exit(34);
		}else
		{
			printf("parten fork third.\n");
			p3=fork();
			if(p3<0)
			{
				printf("child p3 failed to fork\n");	
				return -1;
			}else if(p3==0)
			{
				count+=1;
				printf("child p1 pid =%d,ppid =%d,count=%d\n",getpid(),getppid(),count);
				exit(77);
			}else
			{
				printf("parent waiting\n");				
				r1=wait(&s1);
				r2=wait(&s2);
				r3=wait(&s3);
				printf("r1=%d,s1=%d,r2=%d,s2=%d,r3=%d,s3=%d\n",r1,WEXITSTATUS(s1),r2,WEXITSTATUS(s2),r3,WEXITSTATUS(s3));
				printf("parent pid =%d ,count =%d",getpid(),count);
				return 0;
			}

		}


	}







}
