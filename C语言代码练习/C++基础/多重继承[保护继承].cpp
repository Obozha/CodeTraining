#include <iostream>
using namespace std;

class Animal {
	public:
		Animal() {}
		void eat() {
			cout<< "eat\n"<<endl;
		};
};
class Giraffe:protected  Animal {
	public:
		Giraffe() {}
		void StrechNeck() {
			cout<<"strech\n";
		};
		void take() {
			eat();    //ok
		}
};
int main() {
	Giraffe gir;
	//gir.eat();    //error
	gir.take();   //ok
	gir.StrechNeck();
}

