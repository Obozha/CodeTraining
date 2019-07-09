#include<stdio.h>

int main(){
	int i,a[10],*p=a; // p的初值是a，p指向a[0]
	printf("please enter 10 integer number:");
	for(i=0;i<10;i++){
		scanf("%d",p++);
	} 
	p=a;
	for(i=0;i<10;i++){
		printf("%d ",*++p);
	}
	printf("\n");
	return 0;
} 
