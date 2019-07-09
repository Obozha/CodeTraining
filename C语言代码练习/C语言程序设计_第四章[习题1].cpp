#include<stdio.h>

int main(){
	int a=3,b=4,c=5;
	int x,y;
	printf("a+b>c&&b==c : %d\n",a+b>c&&b==c);
	printf("a||b+c&&b-c : %d\n",a||b+c&&b-c);
	printf("!(a>b)&&!c||1 : %d\n",!(a>b)&&!c||1);
	printf("!(x=a)&&(y=b)&&0) :%d\n",!(x=a)&&(y=b)&&0);
	printf("!(a+b)+c-1&&b+c/2 : %d\n",!(a+b)+c-1&&b+c/2); 
}  
