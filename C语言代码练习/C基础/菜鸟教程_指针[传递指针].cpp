#include<stdio.h>
/* �������� */

double getAvg(int*,int);
int main(){
	/* ����5��Ԫ�ص�����Ԫ�� */
	int balance[5] = {1000,2,3,17,50};
	double avg;
	
	/* ����һ��ָ�������ָ����Ϊ���� */ 
	avg = getAvg(balance,5);
	
	/* �������ֵ */ 
	printf("avg value is :%f\n",avg);
}

double getAvg(int *arr,int size){
	int i,sum=0;
	double avg;
	for(i=0;i<size;i++){
		sum+=arr[i];
	}
	avg=(double)sum/size;
	return avg;
}
