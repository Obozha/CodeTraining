#include<iostream> 
#include<math.h>
using namespace std;

int main(){
	int a=5,b;
	b=(a=3*5,a*4);
	cout<<b<<endl;
	cout<<a<<endl; 
	return 0;
}


