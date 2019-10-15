#include "header.h"
#include <sys/types.h>

int main(int argc,char *argv[]){
	int a[100]={0};
	create(a,100);
	show(a,100);
	syssort(a,100);
	mysort(a,100);
	return 0;
}
