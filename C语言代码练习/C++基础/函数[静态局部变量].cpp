#include<iostream>
using namespace std;
void func();
int n=1; // ȫ�ֱ��� 
int main(){
	static int a; // ��̬�ֲ�����
	int b=-10; 	  // �ֲ�����
	cout<<"a:"<<a
		<<"b:"<<b
		<<"n:"<<n<<endl;
	b+=4; 
	func();
	cout<<"a:"<<a
		<<" b:"<<b
		<<" n:"<<n<<endl;
	n+=10;
	func();
	return 0;
} 

void func(){
	static int a=2;// ��̬�ֲ�����
	int b=5; 	   // �ֲ�����
	a+=2;
	n+=12;
	b+=5;
	cout<<"a:"<<a
		<<" b:"<<b
		<<" n:"<<n<<endl; 
}


