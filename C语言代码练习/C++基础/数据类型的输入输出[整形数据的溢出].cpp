#include<iostream>
#include <locale>           //setlocale������localeͷ�ļ��ж���
using namespace std;

int main() {
	setlocale(LC_ALL, "chs");
	wchar_t c='��';

	wcout<<c<<endl;

	short a,b;
	a=32767;
	b=a+1;
	cout<<"a="<<a<<endl<<"b="<<b<<endl;
	cout<<sizeof( double)<<endl;
	return 0;
}
