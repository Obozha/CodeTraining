#include<stdio.h>
#include<stdarg.h>

double average(int sum,...);

int main(){
	printf("Average of 2,3,4,5 = %f\n",average(4, 2,3,4,5));
		printf("Average of 5,10,15 = %f\n",average(3, 5,10,15));
}

// 函数func()最后一个参数写成省略号，即三个点号(...)
// 省略号之前的那个参数是int,代表了要传递的可变参数的总数。为了使用这个功能 导入stdarg.h头文件

//  va_list类型变量 该类型是在stdarg.h头文件中定义的
// 使用 int 参数和va_start宏来初始化 va_list变量为一个参数列表。宏va_start是在stdarg.h头文件中定义的
// 使用va_arg宏和va_list变量来访问参数列表中的每一项
// 使用宏va_end来清理赋予va_list变量的内存。 
 

double average(int num,...){
	va_list valist;
	double sum = 0.0;
	int i;
	
	
	
	/* 为num个参数初始化valist */
	va_start(valist,num);
	
	/* 访问所有赋给valist的参数 */
	for(i=0;i<num;i++){
		sum+=va_arg(valist,int);
	}
	/* 清理为 valist 保留的内存 */
	va_end(valist);
	return sum/num;
}
