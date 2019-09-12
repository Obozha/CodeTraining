#include<iostream>
using namespace std;

class RMB {
	protected:
		unsigned int yuan;
		unsigned int jf;
	public:
		RMB(unsigned int d,unsigned int c);
		RMB operator+(double d);
		RMB& operator++();
		void display() {
			cout<<(yuan+jf/100.0)<<endl;
		}
};

RMB::RMB(unsigned int d,unsigned int c) {
	yuan=d;
	jf=c;
	while(jf>=100) { // 以使构造时，确保角分值小于100
		yuan++;
		jf-=100;
	}
}


RMB RMB::operator+(double d) {
	return RMB(yuan+d,jf+(d-(int)d)*100);
}

RMB& RMB::operator++() {
	jf++;
	if(jf>=100) {
		jf-=100;
		yuan++;
	}
	return *this;
}

int main() {
	RMB d1(1,60);
	RMB d2(2,50);
	d1=d1+100.5;
	d1.display();
}
