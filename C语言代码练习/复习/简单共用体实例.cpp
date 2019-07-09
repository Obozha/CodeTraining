#include<stdio.h>

int main(){
	union Date{
		int i;
		char ch;
		float f;
	}a;
	a.i=97;
	printf("%d\n",a.i);
	printf("%c\n",a.ch);
	printf("%f\n",a.f);
} 
