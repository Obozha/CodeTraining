#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int a = 3;
	int *p = &a;

	printf("%#x\n",p);	// ȡָ��p��ֵ(��ָ����ڴ��ַ) 
	printf("%#d\n",*p); // ȡָ��pָ������� 
	printf("%#x\n",&p); // ȡ���ָ��p��ֵ�ĵ�ַ 

	printf("%#x\n",&a); // a���ڴ��ַ 

	int b = 4;
	int *q;  // ָ������Ҫָ����ڴ��ַ����һֱ 
	q = &b; 
	
	printf("%#x\n",q);	// ȡָ��p��ֵ(����ַ) ���ָ�� 
	printf("%#d\n",*q); // ȡָ��pָ������� 
	printf("%#x\n",&q); // ȡ���ָ��p��ֵ�ĵ�ַ 

}



