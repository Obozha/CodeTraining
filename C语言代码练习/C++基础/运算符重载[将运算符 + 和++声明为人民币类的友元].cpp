#include<iostream>
using namespace std; 

class RMB{
	protected:
		unsigned int yuan;
		unsigned int jf;
	public:
		RMB(unsigned int d,unsigned int c);
		friend RMB operator+(RMB& s1,RMB& s2);
		friend RMB& operator++(RMB&);
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

RMB operator+(RMB& s1,RMB& s2){
	unsigned int jf=s1.jf+s2.jf;
	unsigned int yuan=s1.yuan+s2.yuan;
	return RMB(yuan,jf);
}

RMB& operator++(RMB& s){
	s.jf++;
	if(s.jf>=100){
		s.jf-=100;
		s.yuan++;
	}
	return s;
}

int main(){
	RMB d1(1,60);
	RMB d2(2,50);
	RMB d3(0,0);
	// d3=d1+d2; // d3=operator+(d1,d2);
	d3=operator+(d1,d2);
	
	// ++d3;
	operator++(d3);
	d3.display();
}
