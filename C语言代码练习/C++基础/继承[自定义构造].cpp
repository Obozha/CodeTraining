#include<iostream>
#include<string.h>
using namespace std; 

class Advisor { //导师类
		int noOfMeeting;
};

class Student { //学生类
	protected:
		char name[40];
		int semesterHours; // 学时
		float average;  //平均分
	public:
		Student(char* pName) {
			strcpy(name, pName);
			average =semesterHours = 0;
		}
		void addCourse(int hours, float grade)  {
			average=semesterHours*average+grade; //总分
			semesterHours +=hours;   //总修学时
			average /=semesterHours;  //平均分
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
		Advisor advisor;  //导师
		int qualifierGrade;  //资格考试分
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
