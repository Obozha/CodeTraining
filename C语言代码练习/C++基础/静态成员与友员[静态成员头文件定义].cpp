#include"student.cpp"
#include<iostream>

using namespace std;

// ��̬��Ա����ռ估��ʼ��������������
void fn(){
	Student s1;
	Student s2;
	cout<<Student::number()<<endl;
}

int main(){
	fn();
	cout<<Student::number()<<endl;
	cout<<Student::noOfStudents; 
	return 0;
} 
