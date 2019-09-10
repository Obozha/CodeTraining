#include<iostream>
#include<string.h>
using namespace std; 

class Advisor { //��ʦ��
		int noOfMeeting;
};

class Student { //ѧ����
	protected:
		char name[40];
		int semesterHours; // ѧʱ
		float average;  //ƽ����
	public:
		Student(char* pName) {
			strcpy(name, pName);
			average =semesterHours = 0;
		}
		void addCourse(int hours, float grade)  {
			average=semesterHours*average+grade; //�ܷ�
			semesterHours +=hours;   //����ѧʱ
			average /=semesterHours;  //ƽ����
		}
		int getHours() {
			return semesterHours;
		}
		float getAverage() {
			return average;
		}
		void display()  {
			cout <<"name = \"" <<name <<"\""
			     <<", hours = " <<semesterHours
			     <<", average = " <<average<<endl;
		}
};

class GraduateStudent:public Student {
	protected:
		Advisor advisor;  //��ʦ
		int qualifierGrade;  //�ʸ��Է�
	public:
		GraduateStudent(char *pName,Advisor& adv):advisor(adv),Student(pName) {
			qualifierGrade=0;
		}
		int getQualifier() {
			return qualifierGrade;
		}
};

void fn(Advisor& advisor){
	GraduateStudent gs("Yen Kay Doodle",advisor);
	gs.display();
}

int  main(){
	Advisor da;
	fn(da);
	return 0;
}
