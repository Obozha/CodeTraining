#include<stdio.h>

int main() {
	char c1,c2;           // ���������ַ�c1��c2
	c1=getchar();       //�Ӽ�������һ����д��ĸ������c1
	if(c1>='a'&&c1<='z')
		printf("%c",c1-32);
	else if(c1>='A'&&c1<='Z')
		printf("%c",c1+32);
	else
		printf("%c",c1);
}
