#include<iostream>
using namespace std;

int *getInt(const char *str){ // ָ�뺯�� 
	int value=20;
	cout<<str<<endl;
	return &value; 
	// warning:���ֲ������ĵ�ַ�����ǲ��׵� 
}

void somefn(const char*str){
	int a=40;
	cout<<str<<endl;
}

int main(){
	int*pr=getInt("Input a value"); // ��ֵȡ�Է��ص�ָ��ֵ
	cout<<*pr<<endl; // ��һ�����*pr
	somefn("It is uncertain.") ;
	cout<<*pr<<endl; // �ڶ������*pr
	return 0; 
} 
