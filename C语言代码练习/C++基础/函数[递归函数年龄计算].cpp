#include<iostream>
using namespace std;
int main(){
	int age(int n);
	cout<<"No.5,age:"<<age(5)<<endl;
	return 0;
} 

int age(int n){
	int c;
	if(n==1) 
		c=10;
	else 
		c=age(n-1)+2;
	return c;
} 


