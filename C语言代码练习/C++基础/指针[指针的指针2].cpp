#include<iostream>

using namespace std;

int main(){
	int x=12345,*p=&x,
	**p1=&p;
	cout<<x<<" "<<*p<<" "<<**p1<<endl;
}
