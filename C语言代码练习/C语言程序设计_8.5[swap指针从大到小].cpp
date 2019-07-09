#include<stdio.h>

// 函数声明 
void swap(int *pt1,int *pt2);
void exchange(int*,int*,int*);

int main(){
	int a,b,c,*p1,*p2,*p3;
	printf("Please enter three numbers:");
	scanf("%d,%d,%d",&a,&b,&c);
	p1=&a;
	p2=&b;
	p3=&c;
	exchange(p1,p2,p3);
	printf("The order is:%d,%d,%d\n",a,b,c);
	return 0;
} 

void exchange(int *q1,int *q2,int *q3){ // 定义将3个变量的值交换的函数 
	if(*q1<*q2)							// 如果a<b 交换a和b的值 
		swap(q1,q2);					
	if(*q1<*q3)							// 如果a<c 交换a和c的值 
		swap(q1,q3);
	if(*q2<*q3)							// 如果b<c 交换b和c的值 
		swap(q2,q3);
}

void swap(int *pt1,int *pt2){ // 定义交换2个变量的值的函数 
	int temp;				 // 交换*pt1和*pt2变量的值 
	temp=*pt1;
	*pt1=*pt2;
	*pt2=temp;	
}

// exchange 函数的作用是对3个数按大小排序 在执行exchange函数过程中 要嵌套调用swap函数
// swap函数的作用是对两个数按大小排序 通过调用swap函数(最多调用3次) 实现三个数的排序 
