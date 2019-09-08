#include<stdio.h>
#include<string.h>

int main() {
	char str[] = "HelloWorld";
	char *pstr;
	pstr = str;
	int len = strlen(str),i;

	for(i=0; i<len; i++) {
		printf("%c", *(pstr+i));
	}
	printf("\n");

	printf("%s\n",pstr);

	for(i=0; i<len; i++) {
		printf("%c", pstr[i]);
	}
	printf("\n");

	for(i=0; i<len; i++) {
		printf("%c",*(str+i));
	}
	printf("\n");


	int var = 20;
	int *ip;

	ip = &var;
	printf("Address of var variable: %p\n", &var  );

	/* 在指针变量中存储的地址 */
	printf("Address stored in ip variable: %p\n", ip );

	/* 使用指针访问值 */
	printf("Value of *ip variable: %d\n", *ip );

	return 0;
}


// 指针与数组 与值 与字符串的关系 
