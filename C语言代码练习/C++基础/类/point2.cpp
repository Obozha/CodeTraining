#include<iostream>
#include<cmath>
#include"point.h"
using namespace std;
void Point::Set(double ix,double iy) {
	x=atan2(iy,ix) ;
	y=sqrt(ix*ix+iy*iy);
}
double Point::xOffset( ) {
	return y*cos(x);
}
double Point::yOffset( ) {
	return y*sin(x);
}
double Point::angle( ) {
	return (180/3.14159) * x;
}
double Point::radius( ) {
	return y;
}

