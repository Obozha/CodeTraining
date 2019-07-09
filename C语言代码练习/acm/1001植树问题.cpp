#include<stdio.h>

int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	if(m>n){
		printf("%d %d",m/n,m%n);
	}
	return 0;
} 
