#include<iostream>
#include<stdio.h>
using namespace std; 
int main() {
	double i=1;
	double sum=0.0;
	while(i<=99){
		sum+=i/(i+1);
		i++;		
	} 
	cout<<"求值结果为"<<sum<<endl;
	return 0; 
}


