#include "my.h"

#define PROMRT "Do you want terminate program?"
char *prompt=PROMRT;

void ctrl_c(signo)
{
	fprintf(stderr,prompt);
}
int main()
{

	struct sigaction act;
	act.sa_handler=ctrl_c;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	if(sigaction(SIGINT,&act,NULL))
	{
		fprintf(stderr,"Install Signal Action Error:%s\n",strerror(errno));
		exit(0);
	}
	printf("process id is %d\n",getpid());
	
	while(1);

}
