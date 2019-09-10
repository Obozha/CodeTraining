#include<iostream>
using namespace std;

class Base {
		int b1;
	protected:
		int b2;
		void fb2() {
			b1=1;
		}
	public:
		int b3;
		void fb3() {
			b1=1;
		}
};

class Pri:private Base {
	public:
		void test() {
			b1=1; // error
			b2=1; // ok
			b3=1; // ok
			fb2();// ok
			fb3();// ok
		}
};

class FromPri:public Pri {
	public:
		void test() {
			b1=1; // error
			b2=1; // error
			b3=1; // error
			fb2(); // error
			fb3(); // error
		}
};

class Pro:protected Base {
	public:
		void test() {
			b1=1;     // error
			b2=1;     // ok
			b3=1;     // ok
			fb2();    // ok
			fb3();    // ok
		}
};

class FromPro:public Pro {
	public:
		void test() {
			b1=1;     // error
			b2=1;     // ok
			b3=1;     // ok
			fb2();    // ok
			fb3();    // ok
		}
};

class Pub:public Base {
	public:
		void test() {
			b1=1; // error
			b2=1; // ok
			b3=1; // ok
			fb2();// ok
			fb3();// ok
		}
};

class FromPub:public Pub {
	public:
		void test() {
			b1=1; // error
			b2=1; // ok
			b3=1; // ok
			fb2();// ok
			fb3();// ok
		}
};

int main() {
	Pri priObj;
	priObj.b1=1;   // error
	priObj.b2=1;   // error
	priObj.b3=1;   // error
	Pro proObj;
	proObj.b1=1;   // error
	proObj.b2=1;   // error
	proObj.b3=1;   // error
	Pub pubObj;
	pubObj.b1=1;   // error
	pubObj.b2=1;   // error
	pubObj.b3=1;   // ok
}
