#include<stdio.h>
int main(){
	/* 局部变量定义 */
	void swap(int*,int*); 
	int a=100,b=200;
	printf("交换前，a的值:%d\n",a);
	printf("交换前，b的值:%d\n",b);
	
	swap(&a,&b);
	
	/* 调用函数来交换值 
	*  &a表示指向a的指针，即变量a的地址 
	*  &b表示指向b的指针，即变量b的地址 
	*/
	
	printf("交换后，a的值:%d\n",a);
	printf("交换后，b的值:%d\n",b);
	
	return 0;
}

void swap(int *x,int *y){
	int temp;
	temp = *x; /* 保护地址x的值 */
	*x = *y; /* 把y*赋值给x* */
	*y = temp; /* 把temp赋值给y* */
	return;
}
