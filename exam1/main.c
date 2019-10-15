#include <stdio.h>
#include "mylib.h"
int main(){
	int a[100]={0};
	init(a,100);
	show(a,100);
	printf("max=%d\n",max(a,100));

	return 0;

}
