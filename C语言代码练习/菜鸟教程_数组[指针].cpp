#include<stdio.h>

int main(){
	/* ����5��Ԫ�ص��������� */
	double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
	double *p;
	int i;
	
	p = balance;
	/* ���������ÿ��Ԫ�ص�ֵ */
	printf("ʹ��ָ�������ֵ\n");
	for(i=0;i<5;i++)
		printf("*(p + %d):%f\n",i,*(p+i));
	
	printf("ʹ��balance��Ϊ��ַ������ֵ\n");
	for(i=0;i<5;i++){
		printf("*(balance + %d):%f\n",i,*(balance+i));
	}
	return 0;
}
