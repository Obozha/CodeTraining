#include<stdio.h>

void inv(int*,int);

int main(){
	int i,a[10]={3,7,9,11,0,6,7,5,4,2};
	printf("The original array:\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	inv(a,10);
	printf("The array has been inverted:\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}

void inv(int *x,int n){	// �β�x��ָ����� 
	int*p,temp,*i,*j,m=(n-1)/2;
	i=x; // ���׵�ַ����i iָ�������鿪ͷ 
	j=x+n-1; // j��ַ�� �׵�ַ+9 jָ��������ĩβ 
	p=x+m; // pΪ�׵�ַ+4 pָ���������м� 
	for(;i<=p;i++,j--){
		temp=*i;
		*i=*j;
		*j=temp;		// *i��*j���� 
	}
} 
