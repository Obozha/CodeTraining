#include<iostream>
using namespace std;

class Base1{ // 虚基类 
	private:
		int a,b;
	public:
		Base1(int aa=0,int bb=0){
			// 构造函数，是带缺省值，或者是无参数
			a=aa;
			b=bb;
			cout<<"Base1 class"<<endl; 
		} 
	
		void Show(){
			cout<<"Base1:a="<<a<<"b="<<b<<endl;
		}
};

class Base2{
	public:
		Base2(){
			cout<<"Base2 class"<<endl;
		}
		
		void show2(){
			cout<<"Base2:"<<endl;
		}
};

class Level1:public Base2,virtual public Base1{
	public:
		Level1(int a,int b):Base1(a,b){
			cout<<"Level1 class!"<<endl;
		}	
};

class Level2:public Base2,virtual public Base1{
	public:
		Level2(int a,int b):Base1(a,b){
			cout<<"Level2 class!"<<endl;
		}
};

class Lastlevel:public Level1,virtual public Level2{
	public:
		Lastlevel(int a,int b):Level1(a,b),Level2(a,b),Base1(a,b){
			//Lastlevel(int a,int b):Level1(a,b), Level2(a,b), Base1(a,b)    
			cout<<"Lastlevel class!"<<endl;	
		}	
};

int main(){
	Lastlevel obj(7,9);
	obj.Show();
	// 直接调用间接基类base的公有成员show()，无二义性
	// obj.show2(); // error
	// 访问间接成员base2的公有成员show()2 存在恶意性 
}
