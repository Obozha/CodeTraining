#include"student.cpp"
#include<iostream>

using namespace std;

// 静态成员分配空间及初始化，不便于重用
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
