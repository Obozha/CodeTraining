#include<iostream>
using namespace std;

class SillyClass{
	public:
		SillyClass(int &i):ten(10),refI(i){
			
		} 
	protected:
		const int ten; // �������ݳ�Ա  ����ʹ��ð���﷨��ʼ������������ 
		int &refI; 	   // �������ݳ�Ա 
};

int main(){
	int i;
	SillyClass sc(i);
	int c(10); 
}
