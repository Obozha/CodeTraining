#include<iostream>
using namespace std;

void ff1(int a,int b){
	cout<<(a*a+b*b)<<endl;
} 

void ff2(int a,int b){
	cout<<(a*a)<<endl;
}

int main(){
	void(*p)(int,int);
	/* ����ָ��p��ָ�����������β������޷���ֵ�ĺ�����ָ�� */
	p=ff1;	
	p(2,5);
	(*p)(2,5);
	p=ff2;
	p(2,5);
	(*p)(2,5);
	return 0;
}
