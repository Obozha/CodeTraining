#include<stdio.h>


// char *gets(char *s)������stdin��ȡһ�е�s��ָ��Ļ�����
// ֱ��һ����ֹ����EOF��
// int puts(const char*s)�������ַ���s��һ��β��Ļ��з�д�뵽stdout 

int main(){
	char str[100];
	printf("Enter a value:");
	gets(str);
	
	printf("\nYou entered:");
	puts(str);
	return 0;
}
