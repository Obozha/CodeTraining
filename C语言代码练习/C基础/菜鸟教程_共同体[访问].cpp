#include<stdio.h>
#include<string.h>

union Data {
	int i;
	float f;
	char str[100];
};

int main() {
	union Data data;

	data.i=10;
	printf("data.i:%d\n",data.i);
	data.f=220.5;
	printf("data.f:%f\n",data.f);
	strcpy(data.str,"C Programming");



	printf("data.str:%s\n",data.str);

	printf("data size===%d",sizeof(data));
	return 0;
}
// �ṹ�������ռ�ڴ泤���Ǹ���Ա����֮�ͣ�ÿ����Առ�����Լ����ڴ浥Ԫ
// ��������ռ�������ڴ������ĳ�Ա�����ĳ��ȡ�
// ��ͬ����һ��������������� ����������ͬ���ڴ�λ�ô��治ͬ����������
// ����һ�����ж��Ա�Ĺ����壬�����κ�ʱ��ֻ����һ����Ա����ֵ �������ṩ��һ��ʹ����ͬ���ڴ�λ�õ���Ч��ʽ�� 
