#include<stdio.h>

int main(){
	int a = 1;
	int b = 2;
	int *p[2];
	
	p[0]=&a;
	p[1]=&b;
	
	printf("%p\n",p[0]); // a的地址
	printf("%p\n",&a);  // a的地址
	printf("%p\n",p[1]); // b的地址
	printf("%p\n",&b); // b的地址 
	printf("%d\n", *p[0]); //p[0]表示a的地址，则*p[0]表示a的值

	printf("%d\n", *p[1]); //p[1]表示b的地址，则*p[1]表示b的值
	 
} 
