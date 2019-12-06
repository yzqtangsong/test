#include "my.h"
void sigtoutine(int dunno)
{
	switch(dunno){
		case 1:
			printf("Get a singnal SIGHUP\n");	
			break;
		case 2:
			printf("Get a singnal SIGINT\n");	
			break;
		case 3:
			printf("Get a singnal SIGQUIT\n");
			break;	

	}
}
int main()
{
	printf("process id is %d\n",getpid());
	signal(SIGHUP,sigtoutine);
	signal(SIGINT,sigtoutine);
	signal(SIGQUIT,sigtoutine);
	while(1);

}
