#include<iostream>
using namespace std;

class A{
	private:
		int x,y;
	public:
		A(int xx,int yy):x(xx),y(yy){}
		
		A(){
			x=0;
			y=0;
		}
		
		A operator+(const A& b){
			// 不加const限定 也可以
			return A(x+b.x,y+b.y);
		}
		
		A operator-(){
			return A(-x,-y);
		}
		
		void show(){
			cout<<"x="<<x<<" y="<<y<<endl;
		}
};

int main(){
	A a1(5,55),a2(6,66),a3;
	a3=a1+a2; // 调用操作符重载函数 a1.operator+(a2)
	a3.show();
	a1=-a1;
	a1.show(); 
}
