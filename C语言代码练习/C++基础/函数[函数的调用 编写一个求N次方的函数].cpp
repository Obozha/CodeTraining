#include<iostream>
using namespace std;

double power(double,int); // 函数声明 

int main(){
	cout<<"5 to the power 2 is "<<power(5,3)<<endl; // 函数调用 
} 

double power(double x,int n){ // 函数定义 
	double val=1.0;
	while(n--){
		val*=x;
	}
	return val;
}


