#include<iostream>
using namespace std;

void ff(int a,int b,int(*p)(int,int)){
	/* 定义指针p是指向有两个整形参数、返回整形值得函数的指针 */
	int x;
	x=(*p)(a,b);  // 或 x=p(a,b);
	cout<<x<<endl; 
}

int min(int a,int b){
	return (a>b?b:a);
}

int max(int a,int b){
	return (a>b?a:b);
}

int sum(int a,int b){
	return (a+b);
}

int main(){
	int a,b,c;
	cout<<"请输入两个整数和一个操作"<<endl;
	cin>>a>>b>>c;
	if(c==1)
		ff(a,b,max);
	else if(c==2)
		ff(a,b,min);
	else
		ff(a,b,sum);	
} 
