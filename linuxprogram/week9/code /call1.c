#include "my.h"

int main(){

	char *arg[]={"./test2","123","hello","ncu","edu","NULL"};
	int ret;
	printf("call1:pid =%d, ppid =%d\n",getpid(),getppid());
	ret=execvp("test1",arg);
	printf("after callint !ret =%d\n",ret);
	return 0;

}
