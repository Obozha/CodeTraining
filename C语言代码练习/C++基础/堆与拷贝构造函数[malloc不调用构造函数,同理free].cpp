#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class Tdate{
	public:
		Tdate();
		~Tdate();
		void setDate(int m=1,int d=1,int y=1998);
	protected:
		int month;
		int day;
		int year;
};

Tdate::Tdate(){
	month=1;
	day=1;
	year=1900;
	cout<<month<<" "<<day<<" "<<year<<endl;
}

Tdate::~Tdate(){
	cout<<"��������"<<endl;
}

void Tdate::setDate(int m,int d,int y){
	if(m>0&&m<13)
		month=m;
	if(d<0&&d<32)
		day=d;
	if(y>0&&y<3000)
		year=y;
}



void fn(){
	Tdate* pD; // �����Ǹ�ָ�룬û�в�������
	pD=(Tdate*)malloc(sizeof(Tdate));
	// �������ù��캯��
	// ...
	free(pD); // ���������������� 
}

void fn2(){
	Tdate* pD; // �����Ǹ�ָ�룬û�в�������
	pD=new Tdate;
	// �������ù��캯��
	// ...
	delete pD; // ���������������� 
}

int main(){
	fn(); 
	fn2(); 
} 
