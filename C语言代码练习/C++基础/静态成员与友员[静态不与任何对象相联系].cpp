#include<iostream>
using namespace std;

class Student{
	public:
		static char* sName(){
			// ��̬��Ա���������ж������
			cout<<noOfStudents<<endl;
			return name; // error�Ǹ�����  
		}	
	protected:
		char name[40];
		static int noOfStudents;
}; 
