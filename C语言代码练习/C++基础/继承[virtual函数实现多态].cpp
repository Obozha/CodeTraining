#include<iostream>
using namespace std; 

class Base{
	public:
		virtual void fn(){
			cout<<"In Base class\n";
		}
}; 

class SubClass:public Base{
	public:
		virtual void fn(){
			cout<<"In SubClass\n";
		}
};

void test(Base &b){
	b.fn();
}

int main(){
	Base bc;
	SubClass sc;
	cout<<"Calling test(bc)"<<endl;
	test(bc);
	cout<<"Calling test(sc)"<<endl;
	test(sc);
}
