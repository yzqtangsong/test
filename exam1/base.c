#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "mylib.h"
void init(int *a,int number){
	int i;
	srand((int)time);
	for(i=0;i<number;i++)
		a[i]=1+(int)(1000.0*rand()/(RAND_MAX+1.0));

}
void show(int * a,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%4d : %4d\n",i,a[i]);
	
	}
}
