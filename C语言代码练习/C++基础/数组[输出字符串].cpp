#include<iostream>
#include<stdio.h>
using namespace std;

// ����ַ���������������������ַ��� 
int main(){
	char chArray[30];
	cin.get(chArray,30);
	int i; 
	for(i=0;chArray[i]!='\0';i++){
		cout<<chArray[i];
	}
	cout<<i; 
	cout<<endl;
	return 0;
} 
