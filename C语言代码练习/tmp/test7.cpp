#include<iostream>
using namespace std;

bool IsSymmetry(unsigned int N) {
	unsigned long i=N,j=0;

	/*先把该整数按低位到高位置换*/
	while(i) {
		j=j*10+i%10;
		i/=10;
	}
	/*再用置换的数与原数比较*/
	if(j==N) {
		return 1;
	} else {
		return 0;
	};
}

bool IsPrime(unsigned int n) {
	int i;
	for(i=2; i<n; i++) {
		if(n%i==0) {
			break;
		}
	}
	if(i<n) {
		return 0;
	} else {
		return 1;
	}
}

int main() {
	unsigned int a;
	cin>>a;
	if(IsPrime(a)&&IsSymmetry(a)) {
		cout<<"yes"<<endl;
	} else {
		cout<<"no"<<endl;
	}
}
