#include<iostream>
using namespace std;

class A {
	protected:
		int x,y;
	public:
		int z;
		A(int xx=0,int yy=0,int zz=0):x(xx),y(yy),z(zz) {

		}
		friend void in(A);
		friend void sh(A);
};

void in(A a1) {
	cout<<"input x,y,z: ";
	cin>>	>>a1.y>>a1.z;
	cout<<a1.x<<" "<<a1.y<<" "<<a1.z<<endl;
}
void sh(A a1) {
	cout<<a1.x<<" "<<a1.y<<" "<<a1.z<<endl;
}

int main() {
	A a(11,22,33);
	sh(a);
	in(a);
	sh(a);
	return 0;
}
