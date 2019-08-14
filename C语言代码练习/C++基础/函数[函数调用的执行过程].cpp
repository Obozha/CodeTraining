#include<iostream>
using namespace std;
int funcA(int x,int y); 
void funcB(int s); 
int main(){
	int a=6,b=12;
	a=funcA(a,b);
	cout<<a<<endl;
	return 0;
} 

int funcA(int x,int y){
	
	int n=5;
	funcB(n);
	return n;
}

void funcB(int s){
	int x=8;
	s=x;
}



