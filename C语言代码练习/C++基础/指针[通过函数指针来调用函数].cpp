#include<iostream>
using namespace std;

void ff1(int a,int b){
	cout<<(a*a+b*b)<<endl;
} 

void ff2(int a,int b){
	cout<<(a*a)<<endl;
}

int main(){
	void(*p)(int,int);
	/* 定义指针p是指向有两个整形参数、无返回值的函数的指针 */
	p=ff1;	
	p(2,5);
	(*p)(2,5);
	p=ff2;
	p(2,5);
	(*p)(2,5);
	return 0;
}
