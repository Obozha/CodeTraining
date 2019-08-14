#include<iostream>
using namespace std;

long fac(int);
int main(){
	int n;
	long y;
	cout<<"Enter a positive integer:";
	cin>>n;
	if(n<0){
		cout<<"n<0,data error!"<<endl;
		return 1;
	}
	y=fac(n); // 函数调用
	cout<<n<<"!="<<y<<endl;
	return 0; 
} 

long fac(int n){
	long f;
	if(n==0||n==1)
		f=1;
	else 
		f=fac(n-1)*n; // 递归调用
	return f; 
} 


