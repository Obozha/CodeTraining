#include<stdio.h>
#include<stdlib.h> 

// �ص�����

void populate_array(int *array,size_t arraySize,int (*getNextValue)(void)){
	for(size_t i=0;i<arraySize;i++)
		array[i]=getNextValue();
} 

// ��ȡ���ֵ
int getNextRandomValue(void){
	return rand();
}

int main(void){
	int myarray[10]; 
	populate_array(myarray,10,&getNextRandomValue);
	// ͨ���ص� ����myarray�ĵ�ַ��sizet��ֵ������getNextRandomValue�ķ�����ַ 
	
	
	for(int i=0;i<10;i++)
		printf("%d ",myarray[i]);
	printf("\n");
	printf(" %d",sizeof(size_t));
	
	
	return 0;
}

// �й��� size_t
// size_t��һ���������ͣ��������޷������Σ�����Χ����һ�����int��unsigned��
// ����ʹ��size_t��Ϊ�˱�֤arraysize�����ܹ����㹻���������������ܴ����ֵ

//  
