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

// int &b=i ����b��һ�����ã����Ǳ���i������
// ���þ���ָ�룬����û������ ���԰����������һ������Ҫ*�Ϳ��Է��ʵ�ָ�� 
