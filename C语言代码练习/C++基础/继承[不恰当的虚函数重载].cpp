#include<iostream>
using namespace std;

class Base{
	public:
		virtual void fn(int x){
			cout<<"In Base class,int x="<<x<<endl;
		}
};

class SubClass:public Base{
	public:
		// ��������������в�ͬ������ 
		virtual void fn(float x){
			cout<<"In SubClass,float x="<<x<<endl;
		}
}; 

void test(Base& b){
	int i=1;
	b.fn(i);
	float f=2.0;
	b.fn(f); 
}

int main(){
	Base bc;
	SubClass sc;
	cout<<"Calling test(bc)"<<endl;
	test(bc);
	cout<<"Calling test(sc)"<<endl;
	test(sc);
}

// ˵�� ������ͬ����ʵ���麯��
// ���� �ƶ�̬Ϊ��һ�ֽӿڣ�����ʵ�֡� 
