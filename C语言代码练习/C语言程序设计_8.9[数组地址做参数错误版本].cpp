#include<stdio.h>

void inv(int*,int);

int main(){
	int i,*arr;
	printf("The original array:\n");
	for(i=0;i<10;i++)
		scanf("%d",arr+i);
	
	printf("binggo");
	inv(arr,10);
	printf("The array has been inverted:\n");
	for(i=0;i<10;i++)
		printf("%d",*(arr+i));
	printf("\n");
	return 0;
	
} 


void inv(int *x,int n){			// ����inv���� ����x��ָ����� 
	int *p,m,temp,*i,*j;
	m=n/2;					// �������� 
	i=x;					// ָ���׵�ַ x ��ֵ��iָ�� [�׵�ַ]
	j=x+n-1;				// ָ���׵�ַ+9 ��ֵ��jָ�� [β��ַ] 
	p=x+m;					// ָ���׵�ַ+5 
	for(;i<p;i++,j--){			// iָ������1 jָ�����1 
		temp=*i;				// ָ��ֵ���ཻ�� 
		*i=*j;
		*j=temp;
	}
	printf("debug/inv");
}


