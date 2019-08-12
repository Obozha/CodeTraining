#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int main(){
	double s=0,x=1;// 初始值
	for(int n=1;fabs(x)>1e-8;n++,x*=(-1.0)*(2*n-3)/(2*n-1)){
		// 项值在比较前要先求绝对值 
		s+=x;
	} 
	s*=4;
	cout<<"the pi is"<<s<<endl;
	return 0;
} 
