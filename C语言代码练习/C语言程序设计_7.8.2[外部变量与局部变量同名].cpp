#include<stdio.h>

int a=3,b=5;
int max(int,int);

int main(){
	int a=8;  // a是局部变量 把全局变量屏蔽了 
	printf("max=%d\n",max(a,b));
	return 0;
	
}

int max(int a,int b){ // a,b是形参 
	int c;
	c=a>b?a:b;    // 把a和b中的最大者存放在c中 
	return c;
}

// 定义max函数，形参a和b是局部变量。 全局变量a和b在max函数范围不起作用
// 所以函数max中的a和b不是全局变量 而是形参a 和 b  
