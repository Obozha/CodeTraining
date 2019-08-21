#include <iostream>
using namespace std;
int main( ) {
	float f=34.5;
	float* fPtr=&f; //浮点指针
	int* iPtr=&f; //warning:将浮点变量的地址赋给整型指针
	iPtr=fPtr; //warning:将浮点指针赋给整型指针
	cout<<f<<endl;
	cout<<"iPtr:"<<iPtr<<"=>"<<*iPtr<<endl;
	cout<<"fPtr:"<<fPtr<<"=>"<<*fPtr
	    <<endl<<endl;
	*iPtr=*fPtr; //隐式数据转换
	cout<<f<<endl;
	cout<<*iPtr<<endl;
	cout<<*fPtr<<endl;
	return 0;
}

