#include<stdio.h>

int main(){
	printf("File:%s\n",__FILE__); // ������ǰ�ļ�����һ���ַ������� 
	printf("Date:%s\n",__DATE__); 
	printf("Time:%s\n",__TIME__); // ��ǰʱ�䣬һ����HH:MM:SS ��ʽ��ʾ���ַ�����  
	printf("Line:%d\n",__LINE__); // ��ǰ���� 
	printf("ANSI:%d\n",__STDC__); // ����������ANSI��׼����ʱ ����Ϊ1 
} 
