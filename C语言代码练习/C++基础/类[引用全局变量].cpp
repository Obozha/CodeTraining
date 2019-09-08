#include<iostream>
using namespace std;

double s=0; // È«¾Ö
void func(){
	float s=0;
	::s=3;
	cout<<sizeof(::s);
} 

int main() {
	func();
}


