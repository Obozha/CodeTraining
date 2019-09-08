
#include<iostream>
#include<string.h> 
using namespace std;

class A{
	private:
		int x,y;
	public:
		A(int xx=0,int yy=0):x(xx),y(yy){
		}
		friend class B;
};

class B{
	private:
		char n[20];
	public:
		B(const char nn[]){
			strcpy(n,nn);
		}
		void sh(A a1){
			cout<<n<<":"<<a1.x<<" "<<a1.y<<endl;
		}
		void sum(A a1){
			cout<<n<<":"<<a1.x+a1.y<<endl;	
		}
};

int main(){
	A a1(111,222);
	B b1("abcdefg");
	b1.sh(a1);
	b1.sum(a1);
	return 0;
}
