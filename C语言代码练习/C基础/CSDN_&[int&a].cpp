#include<stdio.h>

//
//void function(int *a);
//
//void function(int *a){
//	*a = 100;
//} 
//
//int main(){
//	int x = 200;
//	int *b = &x;
//	function(b);
//	printf("%d",x);
//	return 0;
//}



void function(int &a);
void function(int &a){
	a = 100;
}

int main(){
	int x = 200;
	function(x);
	printf("%d",x);
	return 0; 
}

// int &b=i 这里b是一个引用，它是变量i的引用
// 引用就是指针，两者没有区别 可以把引用想象成一个不需要*就可以访问的指针 
