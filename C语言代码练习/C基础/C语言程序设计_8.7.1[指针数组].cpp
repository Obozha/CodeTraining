#include<stdio.h>
#include<string.h>


int main() {
	void sort(char *name[],int n);
	void print(char *name[],int n);
	char *name[]= {"Follow me","BASIC","Great Wall","FORTRAN","Computer design"};
	// char *һ���ĸ�ָ�� �ֱ�ָ�� �ĸ�����


	int n=5;
	sort(name,n); // ����sort���������ַ�������
	print(name,n); // ����print ����������ַ���
	return 0;
}

/**
	strcmp �Ƚ������ַ�
	str1<str2�����ظ���
	str1=str2������0
	str1>str2����������
*/

// deprecated conversion from string constant to 'char*' [-Wwrite-strings]
// ���޳ɵ�    ת��      �� string ���� �� �ַ�ָ��
// name�ڸı��ʱ����ָ��


void sort(char *name[],int n) { 	// ����sort����
	char *temp;
	int i,j,k;
	for(i=0; i<n-1; i++) { // i���������ó�n-1 0~n-2һ�� n-1��
		k=i; // ������С����
		for(j=i+1; j<n; j++)  // ͨ���Ƚϻ����Сֵ����
			if(strcmp(name[k],name[j])>0) // name[k] >name[j]
				k=j;
		if(k!=i) {
			temp=name[i];
			name[i]=name[k];
			name[k]=temp;
		}
	}
}

//void print(char *name[],int n) { // ����print����   char *name[] -> ָ��ָ������ĺ���
//	int i;
//	for(i=0; i<n; i++) {
//		printf("%s\n",name[i]); // ��ָ������Ԫ�ص�˳�����������ָ����ַ���
//	}
//}

void print(char *name[],int n) {
	int i=0;
	char *p;
	p=name[0];
	while(i<n) {
		//[Error] cannot convert 'char**' to 'char*' in assignment 
		// ����Ľ��͵���˼��
		// name+i++ Ϊ����ָ���ָ��/��ַ
		// *(name) -> ȡ��ַ 
		printf("%s\n",*(name+i));
		i++;
	}
}

