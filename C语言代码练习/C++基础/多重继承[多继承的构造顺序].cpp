#include<iostream>
using namespace std;

class OBJ1{
	public:
		OBJ1(){
			cout<<"OBJ1"<<endl;
		}	
};

class OBJ2{
	public:
		OBJ2(){
			cout<<"OBJ2"<<endl;
		}
};

class Base1{
	public:
		Base1(){
			cout<<"Base1"<<endl;
		}
};

class Base2{
	public:
		Base2(){
			cout<<"Base2"<<endl;
		}
};

class Base3{
	public:
		Base3(){
			cout<<"Base3"<<endl;
		}
}; 

class Base4{
	public:
		Base4(){
			cout<<"Base4"<<endl;
		}
};

class Derived:public Base1,virtual public Base2,
				public Base3,virtual Base4{
	protected:
		OBJ1 obj1;
		OBJ2 obj2;			
	public:
		Derived():Base4(),Base3(),Base2(),Base1(),obj2(),obj1()
	{
		cout<<"Derived OK"<<endl;
	}
};

int main(){
	Derived aa;
	cout<<"This is OK"<<endl;
}


