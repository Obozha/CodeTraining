#include<iostream>
using namespace std;

class CSum {
	public:
		CSum(int a=0 ,int b=0) {
			nSum+=a+b;
		}
		int getSum() {
			return nSum;
		}
		void setSum(int sum) {
			nSum=sum;
		}
	private:
		static int nSum;
};

int CSum::nSum=0;

int main() {
	CSum one(10, 2), two;
	cout<<"one: sum = 	"<<one.getSum()<<endl;
	cout<<"two: sum = 	"<<two.getSum()<<endl;
	two.setSum(5);
	cout<<"one: sum = 	"<<one.getSum()<<endl;
	cout<<"two: sum = 	"<<two.getSum()<<endl;
	return 0;

}
