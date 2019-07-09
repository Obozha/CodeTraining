#include<stdio.h>

int main(){
	int sum = 17,count = 5;
	double mean;
	mean = (double)sum/count;
	printf("Value of mean:%f\n",mean);
	
	// 这里要注意的是强制转换类型运算符的优先级大于除法，因此
	// sum的值首先要转换为double型，然后除以count，得到一个类型
	// 为double的值 
