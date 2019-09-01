#include<iostream>
using namespace std;
void swap(int&,int&);
int main(){
	int x=5;
	int y=6;
	cout<<"before swap,x:"<<x<<",y"<<y<<endl;
	swap(x,y);
	cout<<"after swap,x:"<<x<<",y"<<y<<endl;
	return 0;
}

void swap(int &rx,int &ry){
	int temp;
	temp=rx;
	rx=ry;
	ry=temp;
}
