#include<stdio.h>

int main(){
	int a = 1;
	int b = 2;
	int *p[2];
	
	p[0]=&a;
	p[1]=&b;
	
	printf("%p\n",p[0]); // a�ĵ�ַ
	printf("%p\n",&a);  // a�ĵ�ַ
	printf("%p\n",p[1]); // b�ĵ�ַ
	printf("%p\n",&b); // b�ĵ�ַ 
	printf("%d\n", *p[0]); //p[0]��ʾa�ĵ�ַ����*p[0]��ʾa��ֵ

	printf("%d\n", *p[1]); //p[1]��ʾb�ĵ�ַ����*p[1]��ʾb��ֵ
	 
} 
