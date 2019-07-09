#include<stdio.h>

int main(){
	int i=10;
	int *p=&i;
	printf("%d",*p);
	int **q=&p;
	printf("%d",**q);
	int ***r=&q;
	printf("%d",***r);
	return 0;
}
