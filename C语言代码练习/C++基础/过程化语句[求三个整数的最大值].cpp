#include<iostream>
using namespace std;

int main(){
	int nNum1,nNum2,nNum3;
	int nMax;
	cout<<"��������������";
	cin>>nNum1>>nNum2>>nNum3;
	nMax=nNum1;
	if(nMax<nNum2){ // ��1��if��� 
		nMax=nNum2; 
	}
	if(nMax<nNum3){ // ��2��if��� 
		nMax=nNum3;
	}
	cout<<"����ֵΪ��"<<nMax<<endl;
	return 0;
} 
