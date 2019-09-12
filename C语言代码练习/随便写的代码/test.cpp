#include<iostream>
using namespace std;

//void go(int n) {
//	int c[n];
//	for(int k=0; k<n; k++) {
//		c[k]=k;
//	}
//	for(int k=0; k<n; k++) {
//		cout<<c[k]<<" "<<endl;
//	}
//}

int main() {
//	go(10);
//	go(120);
	
	int a=5;
	int b[a];
	for(int i=0;i<a;i++){
		b[i]=i;
	} 
	for(int i=0;i<a;i++){
		cout<<i<<endl;
	} 
	cout<<"====="<<endl;
	a=10;
	for(int i=0;i<a;i++){
		b[i]=i;
	} 
	for(int i=0;i<a;i++){
		cout<<i<<endl;
	} 
}


