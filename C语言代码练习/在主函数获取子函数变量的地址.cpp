#include<stdio.h>
#include<stdlib.h>

main(){
	void function(int ** p);
	int * mainp;
	function(&mainp);
	// printf("mainp的内存地址位%#x\n",mainp);
	// 数据幻影 
	printf("mainp的指向的是值%d\n",*mainp);
}

void function(int ** p){
	int i =5 ;
	printf("i的内存地址位%#x\n",&i);
	*p = &i;
}
