#include<iostream>
using namespace std;
class Animal{
	public:
		void eat(){
			cout<<"eat."<<endl;
		}
};

class Giraffe:private Animal{
	public:
		Giraffe(){
		}
		void StretchNeck(){
			cout<<"stretch neck"<<endl;
		}
		void take(){
			eat();
		}
};

void Func(Giraffe & an){
	an.take();
}

int main(){
	Giraffe gir;
	gir.StretchNeck();
	Func(gir); //ok
}
