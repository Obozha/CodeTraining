#include<stdio.h>

int main() {
	int i,j;
	int temp;
	int a[8]= {10,30,40,89,100,110,120};

	printf("����һ�����������:");
	scanf("%d",&temp);
	
	for(i=6; i>=0; i--) { 
		if(a[i]>n) {
			a[i+1]=a[i]; // ��n�����������ƶ�λ�� 
		} else {
			break; // ���ָ�n�ȣ���nС������ 
		}
	}
	printf("��ǰλ�ã�%d\n",i);
	a[i+1]=n; // ������λ���Ǳ�nС��λ��i��n��ߵ�λ��i�Ѿ�����ƶ�һ����λ
	// ����nҪ������i+1��λ�� 

	for(i=0; i<8; i++) {
		printf("%d ",a[i]);
	}
	// ��� 
}
