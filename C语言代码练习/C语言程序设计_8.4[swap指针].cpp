#include<stdio.h>

void swap(int *p1,int *p2);

int main(){
	int a,b;
	int *pointer_1,*pointer_2;	// pointer_1,pointer_2是int*型变量 
	printf("Please enter two integer numbers:");
	scanf("%d%d",&a,&b);
	pointer_1=&a;
	pointer_2=&b;
	
	if(a<b)
		swap(pointer_1,pointer_2); // 调用swap函数，用指针变量作实参
	printf("max=%d,min=%d\n",*pointer_1,*pointer_2); 
} 

void swap(int *p1,int *p2){
	int *p;
	p=p1;
	p1=p2;
	p2=p;
}
