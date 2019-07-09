#include<stdio.h>

void inv(int*,int);

int main(){
	int i,*arr;
	printf("The original array:\n");
	for(i=0;i<10;i++)
		scanf("%d",arr+i);
	
	printf("binggo");
	inv(arr,10);
	printf("The array has been inverted:\n");
	for(i=0;i<10;i++)
		printf("%d",*(arr+i));
	printf("\n");
	return 0;
	
} 


void inv(int *x,int n){			// 定义inv函数 参数x是指针变量 
	int *p,m,temp,*i,*j;
	m=n/2;					// 遍历边数 
	i=x;					// 指针首地址 x 赋值给i指针 [首地址]
	j=x+n-1;				// 指针首地址+9 赋值给j指针 [尾地址] 
	p=x+m;					// 指针首地址+5 
	for(;i<p;i++,j--){			// i指针增加1 j指针减少1 
		temp=*i;				// 指针值互相交换 
		*i=*j;
		*j=temp;
	}
	printf("debug/inv");
}


