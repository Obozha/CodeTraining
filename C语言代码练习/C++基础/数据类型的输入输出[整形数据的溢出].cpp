#include<iostream>
#include <locale>           //setlocale函数在locale头文件中定义
using namespace std;

int main() {
	setlocale(LC_ALL, "chs");
	wchar_t c='世';

	wcout<<c<<endl;

	short a,b;
	a=32767;
	b=a+1;
	cout<<"a="<<a<<endl<<"b="<<b<<endl;
	cout<<sizeof( double)<<endl;
	return 0;
}
