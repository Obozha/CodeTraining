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


void f3(int X){
	class X x;
	x.m=10; 
	cout<<x.m;
	
}

int main() {
	X x ;
	x.f1();
	x.f2();
	f3(3); 
}


