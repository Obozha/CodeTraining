#include<stdio.h>

int main(){
	char a,b,c;
	scanf("%c %c %c",&a,&b,&c);
	int max =a;
	if(b>max){
		max=b;
	}
	if(c>max){
		max=c;
	}
	printf("%c",max);
	return 0;
}
