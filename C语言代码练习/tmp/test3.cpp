#include<iostream>
using namespace std;

class Computer{
	private:
		int mCoreNum;
	public:
		Computer(int i):mCoreNum(i){
			
		}
		
		int fn()const{
			return mCoreNum;
		}
		
		Computer& operator++(){
			mCoreNum++;
			return (*this);
		}
		
};

int main(){
	Computer c(5);
//	cout<<c.fn()<<endl;
	
	Computer a(7);
	a=c;

	++(++a);
	++c;
	cout<<a.fn()<<endl<<c.fn()<<endl;
	cout<<&a<<endl<<&c;
} 
