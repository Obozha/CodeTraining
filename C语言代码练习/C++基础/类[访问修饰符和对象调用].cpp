#include<iostream>
using namespace std;

class Savings{
	private:
		unsigned accountNumber; // �˺�
		float balance; // �����
	public:
		unsigned int deposit(unsigned amount){
			balance+=amount;
			return balance;
		} 
};

int main(){
	Savings a; 		// ������Ķ��� 
	cout<<a.deposit(100)<<endl;  
}
