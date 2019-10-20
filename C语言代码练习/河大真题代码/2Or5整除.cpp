#include<iostream>
using namespace std;

int main() {
	int input=0;
	cin>>input;
	if(input%5==0&&input%2==0)
		cout<<input<<"可以同时被2和5整除\n";
	else if(input%5==0)
		cout<<input<<"可以被5整除\n";
	else if(input%2==0)
		cout<<input<<"可以被2整除\n";
	else {
		cout<<input<<"不能被2和5任一个数整除\n";
	}
}
