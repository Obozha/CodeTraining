#include<iostream>
#include <iomanip>
using namespace std;

class Currency {
	protected:
		unsigned int yuan;
		unsigned int jf;
	public:
		Currency(double v=0.0) {
			yuan=v;
			jf=(v-yuan)*100.0+0.5;
		}

		virtual void display(ostream& out)=0; // 纯虚函数

};

class RMB:public Currency { // 人民币
	public:
		RMB(double v=0.0):Currency(v) {

		}

		virtual void display(ostream& out) {
			out<<yuan<<'.'<<setfill('0')<<jf<<setfill(' ')<<"RMB";
		}
};

class Dmark:public Currency {
	public:
		Dmark(double v= 0.0) : Currency(v) {}
		virtual void display(ostream& out) {
			out <<yuan <<'.'
			    <<setfill('0') <<setw(2) <<jf<<setfill(' ');
			out<< "DM";
		}
};

class WHQ : public RMB {  //人民币外汇券
	public:
		WHQ(double v=0.0) : RMB(v) {}
		virtual void display(ostream& out) {
			RMB::display(out);
			out<< " WHQ ";
		}
};
// 插入运算符重载不能是成员函数，要么是函数，要么是友员函数
// 所以这里如果想用多态来显示不同行为的对象
// 就需要在基类里边建立一个虚函数display() 
ostream& operator << (ostream & oo, Currency& c) {
	c.display(oo);
	oo<<endl;
	return oo;
}

void fn(Currency& c) {
	cout << " Deposit is " << c <<endl;
}

int main() {
	RMB rmb(5.5);
	fn(rmb);
	WHQ whq(5.6);
	fn(whq);
	Dmark mark(10.6);
	fn(mark);

}
