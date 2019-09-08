#include<iostream>
#include"student.h"

using namespace std;

int main(){
	Student s;
	s.AddCourse(3,4.0); 
	cout<<s.Grade()<<endl;
	cout<<s.Hours()<<endl;
	float gpa=s.Grade();
	int hours=s.Hours();
	// 修改局部变量 
}
