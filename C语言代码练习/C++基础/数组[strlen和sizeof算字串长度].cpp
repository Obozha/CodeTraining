#include<iostream>
#include<string.h>
using namespace std;

// 没有规定数组大小时，用字符串初始化字符数组，
// 数组的长度是字符串中字符个数+1 
 
int main(){
	char ch[]="how are you";
	cout<<"size of array："<<sizeof(ch)<<endl;
	cout<<"size of string:"<<strlen(ch)<<endl;
	return 0;
}
