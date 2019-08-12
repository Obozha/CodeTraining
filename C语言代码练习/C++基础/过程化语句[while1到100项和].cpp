#include<iostream>
#include<stdio.h>
using namespace std; 
int main() {
	int i=1,sum=0;
	while(i<101){
		sum+=i;
		i++;
	}
	cout<<"sum="<<sum<<endl;
	cout<<"i="<<i<<endl;
	return 0;
}


