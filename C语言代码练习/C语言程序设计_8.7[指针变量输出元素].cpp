#include<stdio.h>

int main(){
	int *p,i,a[10];
	p=a;
	printf("Please enter 10 integer number:");
	for(i=0;i<10;i++)
		scanf("%d",p++); // ִ�����һ��forѭ�� p�Ѿ�ָ��a�����ĩβ
		
	// ����������İ취�� ֻҪ�ڵڶ���forѭ��֮ǰ��һ����ֵ��� 
	p=a; 
	for(i=0;i<10;i++,p++)
		printf("%d ",*p);
	printf("\n");
	return 0;
} 

// Error expected "Ҫ��"
// token "�Ǻ�"

// [Error] expected ')' before ';' token Ҫ��)ǰ����;�Ǻ� 
// Line �� Col �� 
