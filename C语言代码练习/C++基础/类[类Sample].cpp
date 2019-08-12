#include<iostream> 
#include<math.h>
using namespace std;
void fn();
int main(){
	fn();
}

class Saving{
	private:
		unsigned accountNumber; // 账号 
		float balance; // 结算额 
	public:
		unsigned int deposit(unsigned amount){
			balance+=amount;
			return balance;
		}
};

void fn(){
	Saving a,b; // 定义类的对象
	cout<<a.deposit(100)<<endl; 
}
