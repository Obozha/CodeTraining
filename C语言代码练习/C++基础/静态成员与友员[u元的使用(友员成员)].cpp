#include<iostream>
using namespace std;

class Student; // ǰ������ ��������
class Teacher{
	// ---
	public:
		void assignGrades(Student &s); // �����ɼ�
	protected:
		int noOfStudents;
		Student *pList[100]; 
};

class Student{
	public:
		friend void Teacher::assignGrades(Student &s);
		// ��ѧ�������Ա��Ա��������ĳ�Ա���� 
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
