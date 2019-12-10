#include "my.h"

#define NUM_THREADS 4

struct sarg
{
	int no;
	int n;
};
struct rarg
{
	int s;
	long t;
};
void *fun(void *t)
{
	pthread_t my_tid;
	struct sarg *pt=(struct sarg *)t;
	struct rarg *pk=(struct rarg *)t;
	int s=0;
	
	for(int i=0;i<=pk->n;i++)
	{
		s+=i;
	}
	my_tid =pthread_self();		
	printf("Thread :%d mt tid is %lx,Hello world\n",(int)pk->no+1,my_tid);
	printf("Thread :%d sum 1 to %d is %d\n",(int)pk->no,pk->n,s);
	pthread_exit(my_tid,(void *)&pk);
	
	return 0;
}

int main()
{
	pthread_t tid;
	int rv ,t;
	struct info a[4];
	for(t=0;t<NUM_THREADS;t++)
	{
		a[t].no=t;
	    a[t].n= 100*(t+1);
		rv=pthread_create(&tid,NULL,(void *(*)())hello,(void*)&a[t]);
		if(rv!=0)
		{
			printf("pthread create is not created...");
			return -1;
		}
		printf("create thread %lx\n",tid);
	}
	printf("GOOD bye\n");
	pthread_exit(NULL);	

}
