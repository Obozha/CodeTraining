#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int a = 3;
	int *p = &a;

	printf("%#x\n",p);	// 取指针p的值(即指向的内存地址) 
	printf("%#d\n",*p); // 取指针p指向的内容 
	printf("%#x\n",&p); // 取存放指针p的值的地址 

	printf("%#x\n",&a); // a的内存地址 

	int b = 4;
	int *q;  // 指针类型要指向的内存地址类型一直 
	q = &b; 
	
	printf("%#x\n",q);	// 取指针p的值(即地址) 随机指向 
	printf("%#d\n",*q); // 取指针p指向的内容 
	printf("%#x\n",&q); // 取存放指针p的值的地址 

}



