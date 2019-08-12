#include<iostream>
#include<stdio.h>
#include<iomanip> 
using namespace std; 
int main() {
	int i,j;
	for(i=1;i<=9;i++){
		cout<<setw(40-3*(i-1))<<1;
		for(j=2;j<=i;j++)
			cout<<setw(3)<<j;
		for(j=i-1;j>=1;j--)
			cout<<setw(3)<<j;
		cout<<endl;
	} // end of for
	return 0;
}


