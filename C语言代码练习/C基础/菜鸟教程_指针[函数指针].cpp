// 函数指针
// 函数指针变量的声明:

// typedef int (*fun_ptr)(int,int); // 声明一个指向同样参数，返回值的函数的指针类型

#include<stdio.h>

int max(int x,int y){
	return x > y? x:y;
} 

int main(void){
	/* p是函数指针 */
	int (*p)(int,int)=&max;
	int a,b,c,d;
	printf("请输入三个数字");
	scanf("%d %d %d",&a,&b,&c);
	
	/* 与直接调用函数等价 d=max(max(a,b)) */
	
	d=p(p(a,b),c);
	printf("最大的数字:%d\n",d);
	return 0;
}
