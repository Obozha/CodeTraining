#include<stdio.h>
#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

int main() {
	long a,b,l=0;
	cout<<"please input two numbers:\n";
	cin>>a>>b;
	cout<<"primes from "<<a<<" to "<<b<<" is\n";
	// 处理 
	if(a%2==0)
		a++;
	for(long m=a;m<=b;m+=2){
		// 步长为2
		int sqrtm=sqrt(m);
		int i;
		for(i=2;i<=sqrtm;i++){ // 判明素数 
			if(m%i==0)
				break;
		} 
		if(i>sqrtm){ // 输出 
			// 素数 
			if(l++%10==0)
				cout<<endl;
			cout<<setw(5)<<m;
		}
	} 
	return 0;
}

