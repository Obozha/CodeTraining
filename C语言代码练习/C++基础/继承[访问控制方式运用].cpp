#include<iostream>
using namespace std;

class Base{
	int b1;
	protected:
		int b2;
		void fb2(){
			b1=1;
		}
	public:
		int b3;
		void fb3(){
			b1=1;
		} 
}; 

class Pri:private Base{
	public:
		void test(){
			b1=1; // error
			b2=1; // ok
			b3=1; // ok
			fb2();// ok
			fb3();// ok
		}
};

class FromPri:public Pri{
	public:
		void test(){
			b1=1; // error
			b2=1; // error
			b3=1; // error
			fb2(); // error
			fb3(); // error	
		}
};

class Pro:protected Base{
	public:
		void test(){
			b1=1; //error
			b2=1; // ok
			b3=1; // ok
			fb2();
		}
};

class FromPro:public Pro{
	public:
		void test(){
			
		}
};
