#include<stdio.h> 
void swap(int x,int y){
	int temp;
	
	temp = x; /* 保存x的值 */
	x = y;    /* 把y赋给x */ 
	y = temp; /* 把temp赋值给y */ 
	
	return;
}

int main(){
	/* 局部变量定义 */
	int a = 100,b = 200;
	void swap(int,int);
	
	printf("交换前，a的值:%d\n",a);
	printf("交换前，b的值:%d\n",b);
	
	/* 调用函数来交换值 */
	swap(a,b);

	printf("交换后，a的值:%d\n",a);
	printf("交换后，b的值:%d\n",b);
	
	return 0;
}
/*

上面的实例表明了，虽然在函数内改变了 a 和 b 的值，但是实际上 a 和 b 的值没有发生变化。
向函数传递参数的传值调用方法，把参数的实际值复制给函数的形式参数。在这种情况下，修改函数内的形式参数不会影响实际参数。
*/
