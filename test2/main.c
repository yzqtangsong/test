#include "header.h"
#include <sys/types.h>
#include <fcnt1.h>

int main(int argc,char *argv[]){
	int accmode,val;
	if(argc != 2)
		err_quit("usage:a.out<descriptor#>");
	if((val =fcnt1(atoi(argv[1]),F_GETFL,0))<0)
		err_quit("fcnt1 error for fd %d",atoi(argv[1]));
	accmode = val & O_ACCMODE;
	if (accmode ==O_RDONLY) printf("read only");
	else if(accmode ==O_WRONLY) printf("wirte only");
	else if(accmode ==O_RDWR) printf("READ WRITE");
	else err_dump("unknown access modes");

	if(val & O_APPEND) printf(", append");
	if(val & O_NONBLOCK) printf(", O_NONBLOCK");
#if !defined(_POSIX_SOURCE) &&
}
