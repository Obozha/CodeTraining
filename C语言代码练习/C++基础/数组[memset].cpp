#include<iostream>
#include<memory.h>

using namespace std;

// void* memset(void*,int,unsigned)
// ����void*��ʾ��ַ
// ������һ�ֽ�һ�ֽڵذ�������������Ϊָ����ֵ 
// ����1���������ʼ��ַ
// ����2������ÿ���ֽڵ�ֵ
// ����3��������ռ���ֽ��� 

int main(){
	int ia1[50];
	int ia2[500];
	memset(ia1,0,50*sizeof(int));
	memset(ia2,0,500*sizeof(int));
	
	for(int i=0;i<50;i++){
		cout<<ia1[i]<<" ";
	} 
	
} 
