#include<iostream>
using  namespace  std;
class Base {
	public:
		virtual void fn() {
			cout<<"In Base\n";
		}
};
class Sub:public  Base {
	public:
		void fn() {
			cout<<"In Sub\n";
		}
};

void test(Base &b) {
	b.fn();
}

int main() {
	Base be;
	Sub sc;
	test(be);
	test(sc);
	return 0;
}

