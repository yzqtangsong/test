#include "mylib.h"
int max(int * a ,int n){

	int i;
	int m=0;
	for(i=0;i<n;i++)
	{
		if(m<a[i])
		m=a[i];
	}
	return m;
}
