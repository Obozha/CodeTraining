#include<iostream>
using namespace std;
void func();
int n; // ȫ�ֱ��� 
int main(){
	int a=0;   // �ֲ�����
	int b=-10; // �ֲ�����
	cout<<"a:"<<a
		<<" b:"<<b
		<<" n:"<<n<<endl;
	b+=4;
	func();
	cout<<"a:"<<a
		<<" b:"<<b
		<<" n:"<<n<<endl;
	return 0;
} 

void func(){
	int a=2; // �ֲ�����
	int b=5; // �ֲ����� 
	int n=1; // �ֲ����� 
	a+=2; b+=5; n+=12;
	cout<<"a:"<<a
		<<" b:"<<b
		<<" n:"<<n<<endl;
}



