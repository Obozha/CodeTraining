#include<stdio.h>
int main(){
	int var = 20; /* ʵ�ʱ��������� */
	int *ip; /* ָ����������� */ 
	ip = &var; /* ��ָ������д���var�ĵ�ַ */
	printf("Address of var variable:%p\n",&var);
	/* ��ָ������д���ĵ�ַ */
	printf("Address stored in ip variable:%p\n",ip);
	/* ʹ��ָ�����ֵ */
	printf("Value of *ip variable:%d\n",*ip);
	return 0; 
}
