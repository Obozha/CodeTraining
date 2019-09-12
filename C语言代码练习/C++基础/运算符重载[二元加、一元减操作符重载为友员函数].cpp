#include<iostream>
using namespace std;

class A{
	private:
		int x,y;
	public:
		A(int xx,int yy):x(xx),y(yy){
			
		}
		
		A(){
			x=0;
			y=0;
		}
		
		friend A operator+(const A& a,const A& b);
		friend A operator-(const A& a);
		void show(){
			cout<<"x="<<x<<" y="<<y<<endl;
		}
};

A operator+(const A& a,const A& b){
	return A(a.x+b.x,a.y+b.y);
}

A operator-(const A& a){
	return A(-a.x,-a.y);
}

int main(){
	A a1(5,55),a2(6,66),a3;
	a3=a1+a2; // 调用操作符重载函数:operator+(a1+a2) 
	a3.show();
	a1=-a1; // 调用操作符重载函数:operator -(a1) 
	a1.show();
}
