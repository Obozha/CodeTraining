#include<iostream>
using namespace std;

class Savings{
	private:
		unsigned accountNumber; // 账号
		float balance; // 结算额
	public:
		unsigned int deposit(unsigned amount){
			balance+=amount;
			return balance;
		} 
};

int main(){
	Savings a; 		// 定义类的对象 
	cout<<a.deposit(100)<<endl;  
}
