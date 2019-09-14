#include <iostream>
#include <iomanip>

using namespace std;

class RMB {
	protected:
		unsigned int yuan;
		unsigned int jf;
	public:
		RMB(double v =0.0) {
			yuan =v;              //yuan�õ�v����������
			jf =(v-yuan)*100.0+0.5;
		}
		
		operator double() {
			return yuan+jf/100.0;
		}
		
		void display(ostream& out) {
			out <<yuan <<'.'
			    <<setfill('0') <<setw(2) <<jf //�磺8����ʾ08
			    <<setfill(' ');
		}
};
ostream& operator <<(ostream& oo, RMB& d) {
	d.display(oo);
	//���ʵ�ֲ����������Ϊ�˼̳�ʱ�ɶ�display����
	return oo;
}
int main() {
	RMB rmb(1.5);
	cout <<"Initially rmb = " <<rmb <<"\n";
	rmb =2.0*rmb;
	cout <<"then rmb = " <<rmb <<"\n";
}

