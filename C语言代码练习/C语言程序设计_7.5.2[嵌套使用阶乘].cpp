#include<stdio.h>

int main(){
	int fac(int n);
	int n,y;
	scanf("%d",&n);
	y=fac(n);
	printf("%d!=%d",n,y); 
}

int fac(int n){
	int f;
	if(n<0)
		printf("n<0,data error");
	else if(n==0||n==1)
		f=1;
	else 
		f=fac(n-1)*n;
	return f;
}
