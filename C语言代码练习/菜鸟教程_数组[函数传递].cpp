#include<stdio.h>

double getAvg(int arr[],int size){
	int i;
	double avg;
	double sum = 0; // �ֲ�������Ҫ��ʼ�������� 
	for(i=0;i<size;i++){
		sum+=arr[i];
	}	
	avg=sum/size;
	return avg;
}

/* �������� */
double getAvg(int[],int);

int main(){
	/* ����5��Ԫ�ص��������� */
	int balance[5] = {1000,2,3,17,50};
	double avg;
	
	/* ����һ��ָ�������ָ����Ϊ���� */
	avg=getAvg(balance,5);
	/* �������ֵ */
	printf("ƽ��ֵ�ǣ�%f",avg);
	return 0;
}


