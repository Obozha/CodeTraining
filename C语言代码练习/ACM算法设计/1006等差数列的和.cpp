#include<stdio.h>

int main(){
	int a,b,c;
	
	scanf("%d %d %d",&a,&b,&c);
	printf("%d",(a+b)*((b-a)/c+1)/2);
	return 0;
}
