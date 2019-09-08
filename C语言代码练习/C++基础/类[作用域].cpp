#include<iostream>
using namespace std;

class X {
	public:
		int  m;
		void  f1( );
		void  f2( );

};
void  X::f1( ) {
	m=5;
}
void  X::f2( ) {
	int  m;
	X::m=2;        //X::m±»Òþ²Ø
}
int main() {
	X x ;
	x.f1();
	x.f2();
	cout<<x.m;
}


