#include<iostream>
using namespace std;

class Display { //显示器类，是抽象类
	public:
		virtual void init()=0;  //纯虚函数
		virtual void write(const char * pString)=0; //输出字符串
};

class Monochrome:public Display { //单色显示器类
		virtual void init();
		virtual void write(const char * pString);
};
void Monochrome::init() { 
	cout<<"init"<<endl;
}

void Monochrome::write(const char * pSring) { 
	cout<<pSring<<endl;
}

int main(){
	Display *d;
	Monochrome m;
	d=&m; 
	d->init();
	d->write("HelloWorld"); 
}
