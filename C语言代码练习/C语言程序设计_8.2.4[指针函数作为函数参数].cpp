#include<stdio.h>

void swap(int *p1,int *p2);		// ��swap���������� 

int main(){
	int a,b;
	int *pointer_1,*pointer_2;	// ��������int*�͵�ָ����� 
	printf("please enter a and b:");
	scanf("%d,%d",&a,&b);		// ������������ 
	
	pointer_1=&a;				// ʹpointer_1ָ��a 
	pointer_2=&b;				// ʹpointer_2ָ��b 
	if(a<b)						// ���a<b ����a<b ����swap���� 
		swap(pointer_1,pointer_2);
	printf("max=%d,min=%d\n",a,b);// ������ 
	return 0;
} 

void swap(int *p1,int *p2){		// ����swap���� 
	int temp;
	temp=*p1;					// ʹ*p1��*p2���� 
	*p1=*p2;
	*p2=temp;
}
