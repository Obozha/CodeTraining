#include<iostream>
using namespace std;

class Student; // 前项声明 类名声明
class Teacher{
	// ---
	public:
		void assignGrades(Student &s); // 给定成绩
	protected:
		int noOfStudents;
		Student *pList[100]; 
};

class Student{
	public:
		friend void Teacher::assignGrades(Student &s);
		// 是学生类的友员成员，教室类的成员函数 
		void show(){
			cout<<gpa<<endl; 
		}
	protected:
		Teacher*pT;
		int semesterHours;
		float gpa;
}; 

void Teacher::assignGrades(Student &s){
	s.gpa=4.0;	
}

int main(){
	Student s; 
	Teacher t;
	t.assignGrades(s); 
	s.show();
} 
