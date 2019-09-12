#include<iostream>
using namespace std;

class Counter{
	private:
		int v1;
		char v2;
	public:
		Counter(int v=0,char vv='?'){
			v1=v;
			v2=vv;
		}
		
		operator char(){
			return v2; // 类型转换函数 
		}
		
		operator int(){
			return v1; // 类型转换函数 
		}
		
		void display(){
			cout<<"Counter:v1="<<v1<<" v2="<<v2<<endl;
		}
		
		friend Counter fn(Counter c); // 友元函数 
};

Counter fn(Counter c){ // 友元函数 
	c.v1=c.v1*2;
	return c;
} 

int main(){
	char x;
	int y;
	Counter c1(64,'%'),c2(99,'@');
	c1.display();
	c2.display();
	c2=fn(12345); // 构造函数，隐式转换 
	c2.display();
	x=(char)c1; // 类型转换函数 
	y=(int)c1;	// 类型转换函数
	cout<<x<<" "<<y<<endl; 
}
