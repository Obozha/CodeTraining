#include<stdio.h>
#include<string.h>

union Data{
	int i;
	float f;
	char str[20];
};

/*
��������Կ�����ͬ��i��f��Ա����
��Ϊ��� ����������ֵռ�����ڴ�λ��
��Ҳ��str��Ա�ܹ���������ԭ�� 
*/

int main(){
	union Data data;
	data.i=10;
	data.f=220.5;
	strcpy(data.str,"C programming");
	
	printf("data.i:%d\n",data.i);
	printf("data.f:%f\n",data.f);
	printf("data.str:%s\n",data.str);
	return 0;
}
