#include<stdio.h>

void inv(int*,int);

// main �����е�ָ�����p����ȷ��ֵ �����main�����в������� ֻ��ָ����� �ͻ��� 

int main(){
	int i,arr[10],*p;
	
	p=arr; // arr�׵�ַ��pָ��
	 
	printf("The original array:\n");
	for(i=0;i<10;i++,p++)
		scanf("%d",p);
	printf("\n");
	p=arr;
	
	
	inv(p,10);
	printf("The array has been inverted:\n");
	for(p=arr;p<arr+10;p++)
		printf("%d ",*p);
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

