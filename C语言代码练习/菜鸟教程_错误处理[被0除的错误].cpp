#include<stdio.h>
#include<stdlib.h> 

int main(){
	int dividend = 20;
	int divisor = 0;
	int quotient;
	
	if(divisor == 0){
		fprintf(stderr,"����Ϊ0�˳�����...\n");
		exit(-1);
	}
	
	quotient = dividend/divisor;
	fprintf(stderr,"quotient ������ֵΪ:%d\n",quotient);
	exit(0);
} 

// �ڽ��г�������ʱ��������������Ƿ�Ϊ0�����һ������ʱ�Ĵ���
// Ϊ�˱�������������� ����Ĵ����ڽ��г�������ǰ���ȼ������Ƿ�Ϊ0 
