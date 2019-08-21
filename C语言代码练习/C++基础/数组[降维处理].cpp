#include<iostream>

using namespace std;
int maximum(int grade[],int num);
int main() {
	int sg[3][4]= { {68,77,73,86},{87,96,78,89},{90,70,81,86} };
	cout<<"the max grade is "<<maximum(&sg[0][0],3*4)<<endl;
	return 0;
}

int maximum(int grade[],int num) {
	int max=0;
	for(int i=0; i<num; i++)
		if(grade[i]>max)
			max=grade[i];
	return max;
}

// 函数调用时，函数参数的实参为整形变量的地址，函数原型中，数组参数的形参为整形数组的首地址，两者类型是匹配的

// 注意 被传递的数组地址不要用数组名表示，要用第一个元素的地址表示。因为数组名表示的是二维数组的首地址，尽管地址值相同，但操作不同。
 
