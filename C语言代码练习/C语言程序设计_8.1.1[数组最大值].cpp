#include<stdio.h>

int main(){
	int a=100,b=10;							// 定义整形变量a,b 并初始化 
	int *pointer_1,*pointer_2;			 	// 定义指向整形数据的指针变量pointer_1,pointer_2 
	pointer_1=&a;							// 把变量a的地址赋给指针变量pointer_1 
	pointer_2=&b;							// 把变量b的地址赋给指针变量pointer_2
	printf("a=%d,b=%d\n",a,b);				// 输出变量a和b的值 
	printf("*pointer_1=%d,*pointer_2=%d",*pointer_1,*pointer_2);
											// 输出a和b的值 
	return 0;
} 
