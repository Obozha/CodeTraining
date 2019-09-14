#include<iostream>
using namespace std;

void fn() {
	char str[128];
	cout<<"Type in a line of text and press Enter"<<endl;
	cin.getline(str,sizeof(str));
	cout<<"You typed:"<<str<<endl;
}

int main() {
	fn();
}

