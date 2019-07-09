#include<stdio.h>
int main(){
	int i,a[10];
	for(i=0;i<=9;i++) // 对数组元素a[0]~a[9]赋值 
		a[i]=i;
	for(i=9;i>=0;i--)
		printf("%d\n",a[i]); // 输出a[9]~a[0]共10个数组元素
	printf("\n");
	return 0; 
}
