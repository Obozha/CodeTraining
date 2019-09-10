#include<iostream>
using namespace std; 

class A{
	private:
		int x,y;
	public:
		virtual void show(int a=0){
			cout<<"A:"<<endl;
			// 声明为虚函数 
		}
};

class B:public A{
	public:
		void show(int a=0){
			cout<<"B:"<<endl;
		}
};

class C:public B{
	public:
		void show(int b=0){
			cout<<"C:"<<endl;
			// 虚函数 
		}
};

class D:public C{
	public:
		void show(int b=0){
			cout<<"D:"<<endl;
		}
};

int main(){
	A a,*pa=&a;
	B b;
	C c;
	D d;
	pa->show();
	pa=&b;
	pa->show();
	pa=&c;
	pa->show();
	pa=&d;
	pa->show(); 
}
// 说明 虚函数可以隔代传播 
