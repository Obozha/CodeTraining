#include<iostream>
using namespace std;

int main(){
	int intOne;
	int& rInt=intOne;
	// 必须被初始化，否则会产生编译错误
	intOne=5;
	cout<<"intOne:"<<intOne<<endl; 
	cout<<"rInt:"<<rInt<<endl;
	rInt=7;
	cout<<"intOne:"<<intOne<<endl;
	cout<<"rInt:"<<rInt<<endl;
	return 0;
}
 
