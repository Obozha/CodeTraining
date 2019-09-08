#include<iostream>
#include"tdate.h"
using namespace std;

void someFunc(Tdate *pS){  // 普通函数 
	pS->Print(); // pS是s对象的指针
	if(pS->IsLeapYear())
		cout<<"leap year"<<endl;
	else 
		cout<<"not leap year"<<endl;
	pS->Set(1,22,1999); 
} 

void someFunc(Tdate &S){
	S.Set(1,22,2000); 
}



int main(){
	Tdate s;
	someFunc(s);
	s.Print(); 
}
