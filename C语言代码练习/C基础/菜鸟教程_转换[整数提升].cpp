#include<stdio.h>

int main(){
	int i = 17;
	char c = 'c'; /* acill:99 */
	int sum;
	
	sum = i + c;
	printf("Value of sum:%d\n",sum);
} 

// 常用的算术转换
// int →unsigned int →long →unsigned long →long long →unsigned long long →float →long double


// 如果一个运算符两边的运算类型不同，先要将其转换成相同的类型
// 即较低类型转换为较高的类型，然后参加运算

// 规则
// char,short[低] -> int -> unsigned -> long -> double -< float[高]

 
 
