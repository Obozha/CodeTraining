#include<iostream>
using namespace std;

int main(){
	int intOne;
	int& rInt=intOne;
	// ���뱻��ʼ�������������������
	intOne=5;
	cout<<"intOne:"<<intOne<<endl; 
	cout<<"rInt:"<<rInt<<endl;
	rInt=7;
	cout<<"intOne:"<<intOne<<endl;
	cout<<"rInt:"<<rInt<<endl;
	return 0;
}
 
