#include<stdio.h>

int main(){
	int age(int);
	printf("No.5,age:%d\n",age(5));
	return 0;
}

int age(int n){ // 对年龄的递归函数 
	int c;		// c用作存放函数的返回值的变量 
	if(n==1)
		c=10;
	else 
		c = age(n-1)+2;
	return c;		
	
}
