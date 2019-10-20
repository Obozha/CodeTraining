#include<iostream>
using namespace std;
class A {
	public:
		A(int j):age(j),num(age+1) {
			cout <<"age:" <<age <<",num:" <<num
			     <<endl;
		}
	protected:
		int age;
		int num;
};
int main( ) {
	A sa(15);
}

