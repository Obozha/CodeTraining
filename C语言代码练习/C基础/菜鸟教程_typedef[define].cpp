#include<stdio.h>

// typedef vs #define
// #define 是C指令，用于为各种数据类型别名，与typedef类似

// typedef 仅限于为类型定义符号名称 #define 不仅可以为类型定义别名 也能为数值别名，
// 比如您可以定义1为ONE
// typedef 是由编译器执行解释的，#define语句是由预编译器进行处理的。 

#define TRUE 1
#define FALSE 0

int main(){
	printf("TRUE的值：%d\n",TRUE);
	printf("TRUE的值：%d\n",FALSE);

}
