#include<stdio.h>

int main(){
	int num,a,b,c;
	scanf("%d",&num);
	
	a=num/100;
	b=num%100/10;
	c=num%100%10;
	
	if(a*a*a+b*b*b+c*c*c==num){
		printf("yes");
	}else{
		printf("no");
	}
	return 0;
}
