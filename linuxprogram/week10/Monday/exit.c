#include "my.h"



int main()
{
	FILE *fp;
	char buf[]="hello world!\n";
	if((fp=fopen("test.txt","w"))==NULL)
		{
			perror("failer to fopen");
			return -1;
		}
	if(fputs(buf,fp)==EOF)
	{
		perror("fail to fputs");
		return -1;
	}
	exit(0);
}
