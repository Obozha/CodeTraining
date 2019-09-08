#include<stdio.h>
#define PI 3.14159

int main(){
	double r,h;
	scanf("%lf %lf",&r,&h);
	printf("%.2lf",2*PI*r*r+2*PI*r*h);
	return 0;
}
