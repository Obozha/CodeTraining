#include<iostream>
using namespace std;

int main() {
	int sumW=0;
	for(int n=1; n<10000; n++) {
		for(int i=1; i<n; i++) {
			if(n%i==0) {
				sumW+=i;
			}
		}
		if(sumW==n) {
			cout<<n<<"ÊÇÍêÊý"<<endl;
		}
		sumW=0;
	}
}
