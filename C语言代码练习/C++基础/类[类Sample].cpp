#include<iostream> 
#include<math.h>
using namespace std;
void fn();
int main(){
	fn();
}

class Saving{
	private:
		unsigned accountNumber; // �˺� 
		float balance; // ����� 
	public:
		unsigned int deposit(unsigned amount){
			balance+=amount;
			return balance;
		}
};

void fn(){
	Saving a,b; // ������Ķ���
	cout<<a.deposit(100)<<endl; 
}
