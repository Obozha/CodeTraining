#include<stdio.h>
#include<math.h>

int main() {
	int year; 
	double interestRate=0.0225,interest,deposit;
	
	scanf("%d %lf",&year,&deposit);
	// year = 2 dep=100;
	
	deposit=deposit*pow(1 + interestRate, year);
	//100* (1+0.0225)*(1+0.0225)
	
	// 1.04550625
	printf("%10.6lf",deposit);
	
	
	
}
