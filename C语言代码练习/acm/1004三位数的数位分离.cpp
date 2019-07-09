#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	printf("%d ",n%10);
	n=n/10;
	printf("%d ",n%10);
	n=n/10;
	printf("%d",n%10);
	printf("\n");
	return 0;
}
