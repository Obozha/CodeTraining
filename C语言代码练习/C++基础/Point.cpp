#include<iostream>
#include<cmath>
#include"Point.h"

using namespace std;

void Point::Set(double ix,double iy){
	x=ix;
	y=iy;
}

double Point::xOffset(){
	return x;
}

double Point::yOffset(){
	return y;
}

double Point::angle(){
	return (180/3.14159)*atan2(x,y);
}

double Point::radius(){
	return sqrt(x*x+y*y); 
}
