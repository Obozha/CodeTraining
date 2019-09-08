#include<stdio.h>

// argc 是argument count的缩写，代表传入main函数的参数的个数；
// argv 是argment vector的缩写，代表传入main函数的参数序列或指针 

/**
 argument  n. 论证；论据；争吵；内容提要
 vector n. 矢量；带菌者；航线 vt. 用无线电导航
*/ 
 
int main(int argc,char * argv[]){
	while(argc-->1){
		printf("%s\n",*++argv);
	}

	// argc-->1 指的是argc先于1比大小 然后再-1 
	// ++argv 则是先加1 再取值 
} 
