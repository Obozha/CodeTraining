#include <iostream>
using namespace std;
const  int  N=5;
void fun();

int  main() {
	for(int i=0; i<N; i++)
	fun();
	return 0;
}

void  fun() {
	static int  a;
	int  b=2;
	a+=3;
	cout<<(a,b)<<endl;
}

