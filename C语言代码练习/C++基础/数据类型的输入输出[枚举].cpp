#include<iostream>
using namespace std;
int main() 
{
//	enum Color{
//		RED,BLUE,GREEN,WHITE,BLACK
//	};
	enum Color{
		RED=100,BLUE=200,GREEN,WHITE=300
	};
	Color paint=BLUE;
	cout<<paint<<endl;
	cout<<GREEN;
	
}

// 通过建立枚举类型定义枚举符
// 枚举类型：是用户自定义类型，属于构造类型，需要列出该数据类型的取值范围。
// 创建枚举类型的格式。

// 枚举类型中列出的枚举符称为枚举常量，它是和整数一一对应的符号 

