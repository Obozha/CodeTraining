#include<iostream>
using namespace std;

const double PI=3.1415926; // PI是一个常量 
int main(){
	double r=100.0,area;
	area=PI*r*r; // 引用PI
	cout<<"圆的面积是："<<area<<"\n";
	return 0; // 指定返回值 
}
