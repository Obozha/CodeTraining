#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int main(){
	// ���� 
	long m;
	int i;
	cout<<"please input a number:\n";
	cin>>m; 
	// ����
	for(i=2;i<m;i++){ // ��m������ 
		if(m%i==0)
			break;
	} 
	if(m==i) // �ж�m�Ƿ�С��m��������
		cout<<m<<"is prime.\n";
	else
		cout<<m<<"isn't prime\n'";
	return 0; 
} 
