#include<stdio.h>

// ʵ����������a���βο���������
// Ҳ����ָ�������


 
void inv(int *x,int n); // inv�������� 

int main(){
	int i,a[10]={0,1,2,3,4,5,6,7,8,9};
	printf("The original array:\n");
	for(i=0;i<10;i++){
		printf("%d ",a[i]);		// ���δ����ʱ�����Ԫ�ص�ֵ 
	}
	printf("\n");
	inv(a,10);					// ����inv���� ���н��� 
	printf("The array has been inverted:\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);		// ��������������Ԫ�ص�ֵ 
	printf("\n");
	return 0;
}

void inv(int x[],int n){ // �β�x�ǲ����� 
	int temp,i,j,m=n/2;
	for(i=0;i<m;i++){
		j=n-1-i;
		temp=x[i];
		x[i]=x[j];
		x[j]=temp;		// ��x[i]��x[j]���� 
	}
}
