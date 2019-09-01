#include<stdio.h>
#include<iostream>
using namespace std;

struct People{
	const char*name;
	const char*age;
};


int main(){
	People p;
	p.name="hLEL";
	cout<<p.name<<endl;
	p.name="thisisinterskdfjlksajfldksa;j";
	cout<<p.name;
	
		 
}
