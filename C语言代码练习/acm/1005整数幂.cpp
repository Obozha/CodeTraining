#include<stdio.h>

int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%-9d",a);
	printf("%-9d",a*a);
	printf("%-9d\n",a*a*a);
	printf("%-9d",b);
	printf("%-9d",b*b);
	printf("%-9d\n",b*b*b);
	printf("%-9d",c);
	printf("%-9d",c*c);
	printf("%-9d\n",c*c*c);
	return 0;
} 
