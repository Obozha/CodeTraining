#include<iostream>
#include<stdio.h>
#include<iomanip> 
using namespace std; 
int main() {
	int i,j,n=0;
	for(i=1;i<=2;i++){
		for(j=1;j<=12;j++)
			cout<<"*";
		cout<<endl;
	}
	for(i=1;i<=5;i++){
		cout<<"***";
		for(j=1;j<=6;j++)
			cout<<" ";
		cout<<"***";
		cout<<endl;
	}
	for(i=1;i<=2;i++){
		for(j=1;j<=12;j++)
			cout<<"*";
		cout<<endl;
	}
	return 0;	
}


