#include<iostream>
using namespace std;
int &fn(int index,int a[]){
	int &r=a[index];
	return r;
}

int main(){
	int a[]={1,3,5,7,9};
	cout<<a[2]<<endl;
	cout<<(fn(2,a)=55)<<endl;
	cout<<a[2]<<endl;
}
