#include<iostream>
#include<iomanip> // 要用到格式控制符
using namespace std;

int main() {
	cout<<setw(10)<<15<<endl; // s


	cout<<setiosflags(ios::right)
	    <<setw(5)<<1
	    <<setw(5)<<2
	    <<setw(5)<<3<<endl;
	cout<<resetiosflags(ios::right)<<setiosflags(ios::left) // 如果再设置
	    <<setw(5)<<1
	    <<setw(5)<<2
	    <<setw(5)<<3<<endl;
	cout<<left
	    <<setw(5)<<1
	    <<setw(5)<<2
	    <<setw(5)<<3<<endl;


}
