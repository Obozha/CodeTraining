#include<stdio.h>
#include<math.h>

double getFactorial(int i);
int main(){
	double x,sum;
	int i,j,flag=1;
	scanf("%lf",&x);
	for(i=0,j=1;i<10;i++,j+=2,flag=-flag){
		sum+=pow(x,j)/getFactorial(j)*flag;
	}
	printf("%.3lf",sum);
	return 0;
}

double getFactorial(int i) {
	if(i==1) {
		return 1;
	}
	return getFactorial(i-1)*i;
}
