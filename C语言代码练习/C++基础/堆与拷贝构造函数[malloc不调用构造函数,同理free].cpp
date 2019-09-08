#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class Tdate{
	public:
		Tdate();
		~Tdate();
		void setDate(int m=1,int d=1,int y=1998);
	protected:
		int month;
		int day;
		int year;
};

Tdate::Tdate(){
	month=1;
	day=1;
	year=1900;
	cout<<month<<" "<<day<<" "<<year<<endl;
}

Tdate::~Tdate(){
	cout<<"析构函数"<<endl;
}

void Tdate::setDate(int m,int d,int y){
	if(m>0&&m<13)
		month=m;
	if(d<0&&d<32)
		day=d;
	if(y>0&&y<3000)
		year=y;
}



void fn(){
	Tdate* pD; // 仅仅是个指针，没有产生对象
	pD=(Tdate*)malloc(sizeof(Tdate));
	// 并不调用构造函数
	// ...
	free(pD); // 并不调用析构函数 
}

void fn2(){
	Tdate* pD; // 仅仅是个指针，没有产生对象
	pD=new Tdate;
	// 并不调用构造函数
	// ...
	delete pD; // 并不调用析构函数 
}

int main(){
	fn(); 
	fn2(); 
} 
