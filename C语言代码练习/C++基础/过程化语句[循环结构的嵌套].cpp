#include<iostream>
#include<stdio.h>
#include<iomanip> 
using namespace std; 
int main() {
	int i,j,n=0;
	cout<<left;
	for(i=1;i<=4;i++) // 累计输出数据 
		for(j=1;j<=5;j++){
			
			cout<<setw(5)<<i*j;
			if(j==5)
				cout<<endl;	
		}
	return 0;
}


