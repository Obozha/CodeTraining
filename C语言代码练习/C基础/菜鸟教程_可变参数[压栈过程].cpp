#include<stdio.h>

void debug_arg(unsigned int,...);

void debug_arg(unsigned int num,...){
	unsigned int i = 0;
	unsigned int *addr = &num;
	
	for(i=0;i<=num;i++){
		/* (addr + i)������������ȡ�������ݵĲ��� ���Ƴ�ջ���� */
		printf("i=%d,value=%d\r\n",i,*(addr+i));
	}
} 

int main(){
	debug_arg(3,66,88,666);
	return 0;
}

// �ɱ�����Ĺ���ԭ�� ��32λ��Ϊ��

// 1.���������Ĵ��ݴ洢��ջ�У���������ѹ��ջ�У�ѹջ����Ϊ�ݼ�
// 2.�����Ĵ�����4�ֽڶ��룬float/double���ﲻ���� 
