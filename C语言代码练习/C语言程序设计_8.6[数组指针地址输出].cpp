#include<stdio.h>


// 这种方法比其他方法快 用指针变量直接指向元素 不必每次都重新计算地址
// 像p++这样的自加操作是比较快的。这种有规律地改变地址 (p++)能大大提高执行效率 
 
int main(){
	int a[10];
	int *p,i;
	printf("Please enter 10 integer numbers:");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]); 
	for(p=a;p<(a+10);p++)
		//printf("%d ",*p);
		printf("%d ",p);
	printf("\n");


	return 0;	
	


}


