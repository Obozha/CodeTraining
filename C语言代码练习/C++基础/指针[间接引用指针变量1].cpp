#include<iostream>
using namespace std;

int main(){
	int *iPtr;
	int iCount=18;
	iPtr=&iCount;
	cout<<*iPtr<<endl; // 间接引用指针 
} 

// 操作符*：取指针变量所指向的单元的内容 
