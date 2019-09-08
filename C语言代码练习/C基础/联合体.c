#include<stdio.h>   //导入头文件 standard input output 
#include<stdlib.h>

main(){
	
	union{long long i; short s; char c} un;
	un.i = 3;
	printf("%d\n",un.i);
	printf("%d\n",sizeof(un));
}
