#include<iostream>
#include<stdio.h>
using namespace std; 
int main() {
	int i=0,j=0,n;
	cout<<"��������������������0���������";
	cin>>n;
	while(n!=0){
		if(n>0)
			i+=1;
		if(n<0)
			j+=1;
		cin>>n;
	}
	cout<<"������������"<<i<<endl;
	cout<<"������������"<<j<<endl;
	return 0;
}


