#include<stdio.h>

int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	// 20 16 18
	int max =a;
	if(b>max){
		max=b;
	}
	if(c>max){
		max=c;
	}
	printf("%d",max);
	return 0;
}
