#include<iostream>
using namespace std;
class Base{
	public:
		virtual Base* afn(){ // �麯�� 
			cout<<"This is Base class.\n";
			return this;
		}
};

class SubClass:public Base{
	public:
		SubClass* afn(){ // �麯�� 
			cout<<"This is SubClass.\n";
			return this;
		}
};

void test(Base& x){
	Base *b;
	b=x.afn();
}

int main(){
	Base bc;
	SubClass sc;
	test(bc);
	test(sc);
}
