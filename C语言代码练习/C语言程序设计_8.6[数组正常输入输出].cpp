#include<stdio.h>


// c编译系统是将a[i]转换为*(a+i)处理的 即先计算元素地址  

int main(){
	int a[10];
	int i;
	printf("please enter 10 integer numbers:");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	
	return 0;
} 
