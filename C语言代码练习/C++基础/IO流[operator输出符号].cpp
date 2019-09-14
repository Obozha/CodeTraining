#include <iostream>
#include <iomanip>

using namespace std;

class RMB {
	protected:
		unsigned int yuan;
		unsigned int jf;
	public:
		RMB(double v =0.0) {
			yuan =v;              //yuan得到v的整数部分
			jf =(v-yuan)*100.0+0.5;
		}
		
		operator double() {
			return yuan+jf/100.0;
		}
		
		void display(ostream& out) {
			out <<yuan <<'.'
			    <<setfill('0') <<setw(2) <<jf //如：8分显示08
			    <<setfill(' ');
		}
};
ostream& operator <<(ostream& oo, RMB& d) {
	d.display(oo);
	//间接实现插入运算符是为了继承时可对display重载
	return oo;
}
int main() {
	RMB rmb(1.5);
	cout <<"Initially rmb = " <<rmb <<"\n";
	rmb =2.0*rmb;
	cout <<"then rmb = " <<rmb <<"\n";
}

