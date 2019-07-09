#include<stdio.h>

void inv(int*,int);

// main 函数中的指针变量p是有确定值 如果在main函数中不设数组 只设指针变量 就会变错 

int main(){
	int i,arr[10],*p;
	
	p=arr; // arr首地址给p指针
	 
	printf("The original array:\n");
	for(i=0;i<10;i++,p++)
		scanf("%d",p);
	printf("\n");
	p=arr;
	
	
	inv(p,10);
	printf("The array has been inverted:\n");
	for(p=arr;p<arr+10;p++)
		printf("%d ",*p);
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

