#include<stdio.h>


// char *gets(char *s)函数从stdin读取一行到s所指向的缓冲区
// 直到一个终止符活EOF。
// int puts(const char*s)函数把字符串s和一个尾随的换行符写入到stdout 

int main(){
	char str[100];
	printf("Enter a value:");
	gets(str);
	
	printf("\nYou entered:");
	puts(str);
	return 0;
}
