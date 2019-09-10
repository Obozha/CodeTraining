#include <iostream>
using namespace std;

class Animal {
	public:
		Animal() {}
		void eat() {
			cout<<"eat"<<endl;
		};
};

class Giraffe:private Animal {
	public:
		Giraffe() {}
		void StrechNeck(double) {
			cout<<"strech"<<endl;
		};
};

class Cat:public Animal {
	public:
		Cat() {}
		void Meaw() {
			cout<<"meaw"<<endl;
		};
};

void Func(Animal & an) {
	an.eat();
}

int main() {
	Cat dao;
	Giraffe gir;
	Func(dao);
	// Func(gir);    //error
}

