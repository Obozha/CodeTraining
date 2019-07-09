#include<stdio.h>
#include<math.h>

int main() {
	int m=0,n=0;
	int squareSum=0,cubeSum=0;

	scanf("%d %d",&m,&n);
	if(m>n) {
		for(; n<=m; n++) {
			if(n%2==0) {
				squareSum+=n*n;
			} else {
				cubeSum+=n*n*n;
			}
		}
	} else {
		for(; m<=n; m++) {
			if(m%2==0) {
				squareSum+=m*m;
			} else {
				cubeSum+=m*m*m;
			}
		}
	}
	printf("%d %d",squareSum,cubeSum);
	return 0;
}
