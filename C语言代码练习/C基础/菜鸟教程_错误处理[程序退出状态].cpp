#include<stdio.h>
#include<stdlib.h>

int main(){
	int dividend = 20;
	int divisor = 0;
	int quotient;
	
	if(divisor == 0){
		fprintf(stderr,"除数为0退出运行...\n");
		exit(EXIT_FAILURE);
	}
	
	quotient = dividend/divisor;
	fprintf(stderr,"quotient 变量的值为%d\n",quotient);
	
	exit(EXIT_SUCCESS);
	
} 

// 程序成功执行完一个操作正常退出的时候会带有值EXIT_SUCCESS。在这里 EXIT_SUCCESS是宏，它被定义为0
// 程序存在一种错误情况，当退出程序时，会带有状态值 EXIT_FAILURE,被定义为-1。 
