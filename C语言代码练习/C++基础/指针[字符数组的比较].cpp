#include<iostream>
using namespace std;

int main(){
	char buffer1[10]="hello";
	char buffer2[10]="hello";
	if(buffer1==buffer2)
		cout<<"equal"<<endl;
	else
		cout<<"not equal"<<endl;
	return 0;
} 
