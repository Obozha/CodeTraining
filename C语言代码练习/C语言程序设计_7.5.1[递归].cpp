#include<stdio.h>

int main(){
	int age(int);
	printf("No.5,age:%d\n",age(5));
	return 0;
}

int age(int n){ // ������ĵݹ麯�� 
	int c;		// c������ź����ķ���ֵ�ı��� 
	if(n==1)
		c=10;
	else 
		c = age(n-1)+2;
	return c;		
	
}
