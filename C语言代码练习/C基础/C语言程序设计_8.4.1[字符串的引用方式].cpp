#include<stdio.h>

int main(){
	char string[] = "I love China";  // �����ַ�����string 
	printf("%s\n",string);			 // ��%s��ʽ�������string��������������ַ���  string ҲΪ�׵�ַ 
	printf("%c\n",string[7]);		 // ��%c��ʽ���һ���ַ�����Ԫ��

	char *string = "HelloWorld";
	printf("%s",string);

	return 0; 
} 
