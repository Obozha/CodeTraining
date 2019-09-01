#include<iostream>
using namespace std;
int main(){
	int a=12345,*p=&a,*&p2=p;
	cout<<a<<" "<<*p<<" "<<*p2<<endl;
	return 0;
}
