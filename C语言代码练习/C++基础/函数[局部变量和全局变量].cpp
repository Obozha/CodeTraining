#include<iostream>
using namespace std;
void func();
int n; // 全局变量 
int main(){
	int a=0;   // 局部变量
	int b=-10; // 局部变量
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
	int a=2; // 局部变量
	int b=5; // 局部变量 
	int n=1; // 局部变量 
	a+=2; b+=5; n+=12;
	cout<<"a:"<<a
		<<" b:"<<b
		<<" n:"<<n<<endl;
}



