#include<stdio.h>
#include<stdlib.h>

main(){
	void function(int ** p);
	int * mainp;
	function(&mainp);
	// printf("mainp���ڴ��ַλ%#x\n",mainp);
	// ���ݻ�Ӱ 
	printf("mainp��ָ�����ֵ%d\n",*mainp);
}

void function(int ** p){
	int i =5 ;
	printf("i���ڴ��ַλ%#x\n",&i);
	*p = &i;
}
