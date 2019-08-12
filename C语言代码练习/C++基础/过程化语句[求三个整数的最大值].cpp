#include<iostream>
using namespace std;

int main(){
	int nNum1,nNum2,nNum3;
	int nMax;
	cout<<"请输入三个整数";
	cin>>nNum1>>nNum2>>nNum3;
	nMax=nNum1;
	if(nMax<nNum2){ // 第1个if语句 
		nMax=nNum2; 
	}
	if(nMax<nNum3){ // 第2个if语句 
		nMax=nNum3;
	}
	cout<<"最大的值为："<<nMax<<endl;
	return 0;
} 
