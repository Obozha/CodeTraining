#include<stdio.h>
#include<stdlib.h>

int main(){
	int dividend = 20;
	int divisor = 0;
	int quotient;
	
	if(divisor == 0){
		fprintf(stderr,"����Ϊ0�˳�����...\n");
		exit(EXIT_FAILURE);
	}
	
	quotient = dividend/divisor;
	fprintf(stderr,"quotient ������ֵΪ%d\n",quotient);
	
	exit(EXIT_SUCCESS);
	
} 

// ����ɹ�ִ����һ�����������˳���ʱ������ֵEXIT_SUCCESS�������� EXIT_SUCCESS�Ǻ꣬��������Ϊ0
// �������һ�ִ�����������˳�����ʱ�������״ֵ̬ EXIT_FAILURE,������Ϊ-1�� 
