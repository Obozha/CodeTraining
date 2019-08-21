#include<iostream>
using namespace std;

int maximum(int[][4],int,int);
int main(){
	int sg[3][4]={ {68,77,73,86},{87,96,78,89},{90,70,81,86} }; 
	cout<<"the max grade is "<<maximum(sg,3,4)<<endl;
	return 0;
}

int maximum(int grade[][4],int pupils,int tests){
	int max=0;
	for(int i=0;i<pupils;i++)
		for(int j=0;j<tests;j++) 
			if(grade[i][j]>max)
				max=grade[i][j];
	return max;
}
// 作为参数传递

// 作为参数传递一个二维数组给函数，其意义也为内存地址，所以原型中
// 声明整数数组参数的形式只能省略第一个下标的形式

// 问题化作遍历二维数组找最大值，传递参数时，除了传递数组名，还要传递行数和列数 
