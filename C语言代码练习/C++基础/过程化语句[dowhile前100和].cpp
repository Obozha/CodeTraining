#include<iostream>
#include<stdio.h>
using namespace std; 
int main() {
	int i=1,sum=0;
	do{
		sum+=i;
		i++;
	} while(i<101);
	cout<<"sum="<<sum<<endl;
}


