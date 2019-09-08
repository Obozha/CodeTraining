#include<stdio.h>
int measure(int a,int b);
int main() {
	int m,n,divisor;
	scanf("%d %d",&m,&n);
	divisor=measure(m,n);
	printf("%d ",divisor);
	
//	double c;
//	c=(double)m*n/divisor;
	
	printf("%.0lf",(double)m*n/divisor);
}

int measure(int a,int b) {
	if(a>0&&b>0) {
		while(a!=b) {
			if(a>b)
				a=a-b;
			else
				b=b-a;
		}
		return a;
	}
	return 0;
}
