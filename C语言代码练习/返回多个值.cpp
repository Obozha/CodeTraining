#include<stdio.h>
#include<stdlib.h>



main(){
	int a = 5;
	int b = 6;
	void add(int *,int *);	// �������� 
	add(&a,&b); 			// ȡab�ڴ��ַָ��ָ�� 
	printf("a:%d,b:%d",a,b);
}

void add(int *a,int *b){
	*a +=15;
	*b +=15;
}
