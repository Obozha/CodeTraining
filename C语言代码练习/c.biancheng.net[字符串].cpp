#include<stdio.h>

int main(){
	// ��������ַ��������Ϊ�ַ�����
	char a[10]; // һά�ַ�����
	char b[5][10]; // ��ά�ַ�����
	char c[20]={'c','.','p','r','o','g','r','a','m'}; // ����������Ԫ�ظ�ֵ
	char d[] = {'c','.','p','r','o','g','r','a','m'}; // ��ȫ��Ԫ�ظ�ֵ����ʡȥ����
	
	char str[30] = {"c.biancheng.net"};
	char str2[30] = "c.biancheng.net"; // ������ʽ���Ӽ�࣬ʵ�ʿ����г���
	// [Error] 'char str [30]' previously declared here
	// Ϊ�˷��㣬Ҳ���Բ�ָ�����鳤�� �Ӷ�д��
	char str3[] = {"HelloWorld"};
	char str4[] = "c.biancheng.net"; // ������ʽ���Ӽ�� ʵ�ʿ����г��� 
	
	// [����] �ַ�����ֻ���ڶ���ʱ���ܽ������ַ���һ���Եظ�ֵ���� 
	// ��������  ��ֻ��һ���ַ�һ���ַ��ĸ�ֵ
	
	char str5[7];
	// str = "abc123" error 
	
	str5[0] = 'a';
	str5[1] = 'b';
	str5[2] = 'c';
	str5[3] = '1';
	str5[4] = '2';
	str5[5] = '3';
	
} 
