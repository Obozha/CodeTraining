#include<iostream>
#include<stdio.h>
using namespace std;

// 输出字符数组名，可以输出整个字符串 
int main(){
	char chArray[30];
	cin.get(chArray,30);
	int i; 
	for(i=0;chArray[i]!='\0';i++){
		cout<<chArray[i];
	}
	cout<<i; 
	cout<<endl;
	return 0;
} 
