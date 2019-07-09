#include<stdio.h>
#include<stdlib.h>

main(){
	int swap(int*,int*);
	int a = 3;
	int b = 5;
	printf("a 的值是 %d,b 的值是 %d\n",a,b);
	swap(&a,&b);
	printf("a 的值是 %d,b 的值是 %d\n",a,b);
}

void swap(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
