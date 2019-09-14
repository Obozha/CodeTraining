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

		virtual void display(ostream& out)=0; // ���麯��

};

class RMB:public Currency { // �����
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

class WHQ : public RMB {  //��������ȯ
	public:
		WHQ(double v=0.0) : RMB(v) {}
		virtual void display(ostream& out) {
			RMB::display(out);
			out<< " WHQ ";
		}
};
// ������������ز����ǳ�Ա������Ҫô�Ǻ�����Ҫô����Ա����
// ��������������ö�̬����ʾ��ͬ��Ϊ�Ķ���
// ����Ҫ�ڻ�����߽���һ���麯��display() 
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
