#include<iostream>
using namespace std; 

int c;
int f(int a,int b){
	c=0;
	return a+b;
}

int main(){
	c=100;
	int b=f(10,100);
	cout<<c+b;
} 
