#include<iostream>

using namespace std; 

int main(){
	int x=100,y=x+200;
	int *p=&y;
	cout<<y<<" "<<*p<<" "<<p<<endl;
	 
}
