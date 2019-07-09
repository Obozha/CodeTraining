#include<stdio.h>
double getFactorial(int i);
int main() {
	int i,n=0;
	scanf("%d",&n);
	if(n<=20) {
		for(i=1; i<=n; i++) {
			printf("%-4d%-20.0lf\n",i,getFactorial(i));
		}
	}
}

double getFactorial(int i) {
	if(i==1) {
		return 1;
	}
	return getFactorial(i-1)*i;
}
