#include<iostream>
using namespace std; 

class RMB{
	protected:
		unsigned int yuan;
		unsigned int jf;
	public:
		RMB(unsigned int d,unsigned int c);
		 RMB operator+(RMB& s);
		 RMB& operator++();
		void display(){
			cout<<(yuan+jf/100.0)<<endl;
		}
};

RMB::RMB(unsigned int d,unsigned int c){
	yuan=d;
	jf=c;
	while(jf>=100){ // 以使构造时，确保角分值小于100 
		yuan++;
		jf-=100;		
	}
}

RMB RMB::operator+(RMB& s){
	unsigned int c=jf+s.jf;
	unsigned int d=yuan+s.yuan;
	return RMB(d,c);
}

RMB& RMB::operator++(){
	jf++;
	if(jf>=100){
		jf-=100;
		yuan++;
	}
	return *this;
}

int main(){
	RMB d1(1,60);
	RMB d2(2,50);
	RMB d3(0,0);
	d3=d1+d2; // d3=d1.operator+(d2);
	++d3;	  // d3.operator++();
	d3.display();
}
