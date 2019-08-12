#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int main(){
	// 输入 
	long m;
	int i;
	cout<<"please input a number:\n";
	cin>>m; 
	// 处理
	for(i=2;i<m;i++){ // 找m的因数 
		if(m%i==0)
			break;
	} 
	if(m==i) // 判断m是否被小于m的整数除
		cout<<m<<"is prime.\n";
	else
		cout<<m<<"isn't prime\n'";
	return 0; 
} 
