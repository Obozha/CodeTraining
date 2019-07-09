#include<stdio.h>
#include<stdlib.h> 

int main(){
	int dividend = 20;
	int divisor = 0;
	int quotient;
	
	if(divisor == 0){
		fprintf(stderr,"除数为0退出运行...\n");
		exit(-1);
	}
	
	quotient = dividend/divisor;
	fprintf(stderr,"quotient 变量的值为:%d\n",quotient);
	exit(0);
} 

// 在进行除法运算时，如果不检查除数是否为0，则会一个运行时的错误
// 为了避免这种情况发生 下面的代码在进行除法运算前会先检查除数是否为0 
