#include<stdio.h>

int main() {
	int input=0,i,j;
//	scanf("%d",&input);
	for(j=2; j<=1000; j++) {
		for(i=2; i<j; i++) {
			if(j%i==0)
				break;
		}

		if(i<j) {
//			printf("%d Not a prime number",input);
		} else {
			printf("%d is a prime number\n",j);
		}
	}
}
