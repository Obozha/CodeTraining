#include<stdio.h>
#include<stdlib.h>
#include<malloc.h> 


main(){
	
	int i = 5; // ջ 
	int arr[] = {1,2,3}; // ջ
	int * p =  malloc(sizeof(int) * 10);
	*p = 10;
	*(p+1) = 20;
	printf("%#x\n",p);
	printf("%d\n",*p);
	printf("%d\n",*(p+1));
}
