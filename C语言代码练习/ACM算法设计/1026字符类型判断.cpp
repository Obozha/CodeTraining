#include<stdio.h>

int main() {
	char c1,c2;           // ���������ַ�c1��c2
	c1=getchar();       //�Ӽ�������һ����д��ĸ������c1
	if(c1>='a'&&c1<='z')
		printf("lower");
	else if(c1>='A'&&c1<='Z')
		printf("upper");
	else if(c1>='0'&&c1<='9') 
		printf("digit");
	else
		printf("other");
}
