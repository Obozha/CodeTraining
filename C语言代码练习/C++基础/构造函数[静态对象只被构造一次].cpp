#include<iostream>
using namespace std;

class SmallOne{
	public:
		SmallOne(int sma){
			cout<<"SmallOne constructing with a value of"<<sma<<endl;
		}
};

void fn(int n){
	static SmallOne sm(n);
	cout<<"In function fn with n="<<n<<endl;
}

int main(){
	fn(10);
	fn(20);
}
