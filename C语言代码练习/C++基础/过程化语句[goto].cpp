#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
	int i=1,sum=0;
	loop:sum=sum+i;
	++i;
	if(i<101)goto loop;
	cout<<"sum="<<sum;
}


