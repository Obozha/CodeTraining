#include<iostream>
#include<strstream>
using namespace std; 

char* parseString(const char* pString) {
	istrstream inp(pString,0); //ios::in��ʽ������Null����
	int aNumber;
	float balance;
	inp >>aNumber >>balance; //�Ӵ����ж���һ�������͸�����
	char* pBuffer =new char[128];
	ostrstream outp(pBuffer,128); //ios::out��ʽ���ִ�����128
	outp <<"a Number = " <<aNumber       //д��pBuffer��
	     <<", balance = " <<balance<<'\0';
	return pBuffer;
}
int main() {
	const char* str ="1234 100.35";
	char* pBuf =parseString(str);
	cout <<pBuf <<endl;
	delete[]pBuf;
}

