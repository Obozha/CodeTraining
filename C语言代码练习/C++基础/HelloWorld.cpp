// HelloWorld.cpp 第一个程序
/*
	该程序的功能是输出 HelloWorld 

*/ 

// 单行注释

// 注释的目的是增加程序可读性，计算机不会执行注释中的语句 

#include<iostream>
// include：编译预处理命令，文件包含

// iostream.h 是C++为了特定环境编制的标准输入/输出流的标注头文件
// 也就是说，这个头文件提供了输入/输出设施。

// int main() 主函数，程序的入口，一个C++程序，有且只能有一个main函数。main是函数名
// int 表示整数（integer）数据类型，位于main前面，表示main函数应该返回一个整数值

// 一个花括号{...} 是表示main的函数体 

using namespace std;
 
int main(){
	double i=123e5;
	cout<<sizeof(3.44f)<<endl;
	return 0;
} 

 
