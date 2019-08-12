#include<iostream>
#include<stdio.h>
using namespace std;

#define PI 3.1416
#define AREA(R) PI*R*R
#define CUBE(X) ((X)*(X)*(X))

double Area(double r){
	double t;
	const double pi=3.1416;
	t=pi*r*r;
	return t;
} 

double Cube(double s){
	double q;
	q=s*s*s;
	return q;
}

int main(){
	int a=AREA(3);
	cout<<"AREA(R)="<<AREA(3+3)<<endl;  // »»³É3+3ÈçºÎ?
	cout<<"Area(r)="<<Area(3+3)<<endl;
	
	int height=100;
	cout<<"CUBE(s)"<<CUBE(height++)<<endl;
	cout<<"height="<<height<<endl; 
	height=10;
	cout<<"Cubes(s)"<<Cube(height++)<<endl;
	cout<<"height="<<height<<endl;
	return 0;
}
