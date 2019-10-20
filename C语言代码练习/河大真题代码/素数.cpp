#include<iostream>
#include<math.h>
using namespace std;

int main() {
	while(1) {
		int i,input;
		cin>>input;
		int m=sqrt(input);
		for(i=2; i<=m; i++) {
			if(input%i==0) {
				break;
			}
		}
		if(i>m) {
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl; 
		}
	}
}
