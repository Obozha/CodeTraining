#include<iostream>

using namespace std;
int maximum(int grade[],int num);
int main() {
	int sg[3][4]= { {68,77,73,86},{87,96,78,89},{90,70,81,86} };
	cout<<"the max grade is "<<maximum(&sg[0][0],3*4)<<endl;
	return 0;
}

int maximum(int grade[],int num) {
	int max=0;
	for(int i=0; i<num; i++)
		if(grade[i]>max)
			max=grade[i];
	return max;
}

// ��������ʱ������������ʵ��Ϊ���α����ĵ�ַ������ԭ���У�����������β�Ϊ����������׵�ַ������������ƥ���

// ע�� �����ݵ������ַ��Ҫ����������ʾ��Ҫ�õ�һ��Ԫ�صĵ�ַ��ʾ����Ϊ��������ʾ���Ƕ�ά������׵�ַ�����ܵ�ֵַ��ͬ����������ͬ��
 
