#include<iostream>
#include<stdio.h>
using namespace std; 
void action1(int,int);
void action2(int,int);
int main() {
	while(1) {
		char ch;
		int a=15,b=23;
		cin>>ch;
		switch(ch) {
			case 'a':
			case 'A':
				action1(a,b);
				break;
			case 'b':
			case 'B':
				action2(a,b);
				break; 
			default:
				putchar('\a');
				break; 
		}
	}
}

void action1(int x,int y){
	cout<<"x+y="<<x+y<<endl; 
}

void action2(int x,int y){
	cout<<"x*y="<<x*y<<endl;
}
