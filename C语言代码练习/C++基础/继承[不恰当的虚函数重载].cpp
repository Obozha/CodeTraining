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
		// 参数类型与基类中不同是重载 
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

// 说明 参数不同不能实现虚函数
// 所以 称多态为“一种接口，多种实现” 
