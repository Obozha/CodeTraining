#include<iostream>

using namespace std; 

class Student{
	public:
		static int number(){
			return noOfStudents;
		}
	protected:
		char name[40];
		static int noOfStudents;
}; 

int Student::noOfStudents=1;
int main(){
	Student s;
	cout<<s.number()<<endl; 		// ok �ö������þ�̬��Ա����
	cout<<Student::number()<<endl;  // ok ������������̬��Ա���� 
}
