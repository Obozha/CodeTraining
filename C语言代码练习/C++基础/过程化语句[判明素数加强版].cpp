#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int main() {
	// 输入
	long m;
	int i;
	cout<<"please input a number:\n";

	while(1) {
		cin>>m;
		// 处理
		double sqrtm=sqrt(m);
		for(i=2; i<=sqrtm; i++) {
			if(m%i==0)
				break;
		}
		// 输出
		if(sqrtm<i)
			cout<<m<<"is prime.\n";
		else
			cout<<m<<"isn't prime\n";

	}
	return 0;
}

