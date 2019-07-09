#include<stdio.h>

int main() {
	char *a = "I love China!";
//	a=a+7;						// 改变指针变量的值，即改变指针变量的指向
	printf("%c",a[11]);
	printf("%c",a[0]);
//	printf("%c",a+1); // 输出的是地址 
//	printf("%c",a+1);			// 输出从a指向的字符开始的字符串
	
	return 0;
}
