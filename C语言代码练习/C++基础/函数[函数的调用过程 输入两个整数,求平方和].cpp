#include<iostream>
using namespace std;

int main(){
	int a,b,fun1(int,int);
	cin>>a>>b;
	cout<<"a、b的平方和："<<fun1(a,b)<<endl;
	return 0;
} 

int fun1(int x,int y){
	int fun2(int);
	return (fun2(x)+fun2(y));
}

int fun2(int m){
	return (m*m);
}



