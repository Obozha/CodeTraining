#include<stdio.h>
#include<math.h>

//  s=(a+b+c)/2;
//  area=sqrt(s*(s-a)*(s-b)*(s-c));

int main(){
	double a,b,c,s,area;
	scanf("%lf %lf %lf",&a,&b,&c);
	s=(a+b+c)/2;
	printf("%.2lf",sqrt(s*(s-a)*(s-b)*(s-c)));
	return 0;
}
