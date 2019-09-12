#include<iostream>
using namespace std;

class Increase{
	private:
		int value;
	public:
		Increase(int x):value(x){}; // 构造函数 
		
		Increase& operator++();  // 前增量
		Increase operator++(int);// 后增量 
		 
		void display(){
			cout<<"the value is "<<value<<endl;
		} 
};

Increase& Increase::operator++(){ // 前增量 
	value++;
	return *this;
}

Increase Increase::operator++(int){// 后增量 
	Increase temp(*this); // 临时对象存放有对象值
	value++; 
	return temp;		  // 返回原有对象值 
}

int main(){
	Increase n(20);
	n.display();
	
	(n++).display();
	// 这里返回的是临时对象的显示20  
	
	n.display();
	// 这里是刚刚后自增过的n 
	
	++n;
	n.display();
	// 这里是前增量过的 
	
	++(++n);
	n.display();
	// 24 第一次前自增会返回左值，然后再次自增 
	
	(n++)++; 
	n.display(); 
	// 25 第一次会自增，然后返回临时变量，第二次自增就加到临时对象了 
}
