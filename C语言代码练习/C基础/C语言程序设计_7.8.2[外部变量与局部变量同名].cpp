#include<stdio.h>

int a=3,b=5;
int max(int,int);

int main(){
	int a=8;  // a�Ǿֲ����� ��ȫ�ֱ��������� 
	printf("max=%d\n",max(a,b));
	return 0;
	
}

int max(int a,int b){ // a,b���β� 
	int c;
	c=a>b?a:b;    // ��a��b�е�����ߴ����c�� 
	return c;
}

// ����max�������β�a��b�Ǿֲ������� ȫ�ֱ���a��b��max������Χ��������
// ���Ժ���max�е�a��b����ȫ�ֱ��� �����β�a �� b  
