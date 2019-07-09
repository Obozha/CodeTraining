#include<stdio.h>

void debug_arg(unsigned int,...);

void debug_arg(unsigned int num,...){
	unsigned int i = 0;
	unsigned int *addr = &num;
	
	for(i=0;i<=num;i++){
		/* (addr + i)从左往右依次取出来传递的参数 类似出栈过程 */
		printf("i=%d,value=%d\r\n",i,*(addr+i));
	}
} 

int main(){
	debug_arg(3,66,88,666);
	return 0;
}

// 可变参数的工作原理 以32位机为例

// 1.函数参数的传递存储在栈中，从右至左压入栈中，压栈过程为递减
// 2.参数的传递以4字节对齐，float/double这里不讨论 
