#include<iostream>
#include<string.h>

using namespace std;

class Advisor { // ��ʦ��
		int noOfMeeting;
};

class Student { // ѧ����
	protected:
		char name[40];
		int semesterHours; // ѧʱ
		float average; 	   // ƽ����
	public:
		Student(const char *pName="no name") {
			strcpy(name,pName);
			average=semesterHours=0;
		}

		void addCourse(int hours,float grade) {
			average=semesterHours*average+grade;// �ܷ�
			semesterHours+=hours;   // ����ѧʱ
			average/=semesterHours; // ƽ����
		}

		int getHours() {
			return average;
		}

		float getAverage() {
			return average;
		}

		void display() {
			cout <<"name = \"" <<name <<"\""
			     <<", hours = " <<semesterHours
			     <<", average = " <<average<<endl;
		}
};

class GraduateStudent:public Student{
	// �о����ࣨ�̳�ѧ���ࣩ
	protected:
		Advisor advisor;    // ��ʦ
		int qualifierGrade; // �ʸ��Է�  
	public:
		int getQualifier(){
			return qualifierGrade;
		} 
};

int main(){
	Student ds("Lo lee undergrade");
	GraduateStudent gs;
	ds.addCourse(3,2.5);
	ds.display();
	gs.addCourse(3,3.0);
	gs.display();
}
