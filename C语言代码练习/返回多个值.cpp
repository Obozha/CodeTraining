#include<stdio.h>
#include<stdlib.h>



main(){
	int a = 5;
	int b = 6;
	void add(int *,int *);	// 声明方法 
	add(&a,&b); 			// 取ab内存地址指向指针 
	printf("a:%d,b:%d",a,b);
}

void add(int *a,int *b){
	*a +=15;
	*b +=15;
}
