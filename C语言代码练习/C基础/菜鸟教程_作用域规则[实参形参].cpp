#include<stdio.h>

int test(int,int); // �βΣ�ֻ���� 

int main(){
	int a,b;
	printf("%d",test(5,3));
	return 0; 
} 

int test(int a,int b){ // �β� 
	a = a+b;
	return a;
}
