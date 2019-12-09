#include "my.h"

#define NUM_THREADS 4
void hello(void *t,int n)
{
	pthread_t my_tid;
	int i;
	int sum=0;
	my_tid =pthread_self();
	
	for(i=1;i<n;i++)
		{
			sum+=i;			
		}
		
		printf("Thread :%dcreate thread %lx ,the sum is %d\n",t,my_tid,sum);
		sum=0;

}

int main()
{
	pthread_t tid;
	int rv ,t;
	int n=100;
	for(t=0;t<NUM_THREADS;t++)
	{
		rv=pthread_create(&tid,NULL,(void *(*)())hello,(void*)t);
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
