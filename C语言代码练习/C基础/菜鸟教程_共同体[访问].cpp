#include<stdio.h>
#include<string.h>

union Data {
	int i;
	float f;
	char str[100];
};

int main() {
	union Data data;

	data.i=10;
	printf("data.i:%d\n",data.i);
	data.f=220.5;
	printf("data.f:%f\n",data.f);
	strcpy(data.str,"C Programming");



	printf("data.str:%s\n",data.str);

	printf("data size===%d",sizeof(data));
	return 0;
}
// 结构体变量所占内存长度是各成员长度之和，每个成员占有其自己的内存单元
// 共用体所占变量的内存等于最长的成员变量的长度。
// 共同体是一种特殊的数据类型 允许您在相同的内存位置储存不同的数据类型
// 定义一个带有多成员的共用体，但是任何时候只能有一个成员带有值 共用体提供了一种使用相同的内存位置的有效方式。 
