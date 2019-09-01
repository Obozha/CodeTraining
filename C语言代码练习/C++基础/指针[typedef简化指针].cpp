#include<iostream>
using namespace std;

void f();
typedef void (*FunP)();

int main(){
	FunP fp;
	fp=f;
	fp();
}

void f(){
	cout<<"HelloWorld"<<endl;
} 
