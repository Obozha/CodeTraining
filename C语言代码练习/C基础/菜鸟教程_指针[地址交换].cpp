#include<stdio.h>

int main(){
	char a[]="Hello";
	char b[]="world";
	
	char c[5];
	char *p,*q;
	p=a;
	q=b;
	
	c=*p;
	
	 
} 
int swap(int x,int y){
	int c;
	c=x;
	x=y;
	y=c;
	return 0;
}

int swap2(int *x,int *y){
	int d;
	d=*x;
	*x=*y;
	*y=d;
}
