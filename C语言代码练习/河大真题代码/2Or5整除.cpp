#include<iostream>
using namespace std;

int main() {
	int input=0;
	cin>>input;
	if(input%5==0&&input%2==0)
		cout<<input<<"����ͬʱ��2��5����\n";
	else if(input%5==0)
		cout<<input<<"���Ա�5����\n";
	else if(input%2==0)
		cout<<input<<"���Ա�2����\n";
	else {
		cout<<input<<"���ܱ�2��5��һ��������\n";
	}
}
