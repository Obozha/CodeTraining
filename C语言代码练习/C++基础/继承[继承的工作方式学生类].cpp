#include<iostream>
#include<string.h>

using namespace std;

class Advisor { // 导师类
		int noOfMeeting;
};

class Student { // 学生类
	protected:
		char name[40];
		int semesterHours; // 学时
		float average; 	   // 平均分
	public:
		Student(const char *pName="no name") {
			strcpy(name,pName);
			average=semesterHours=0;
		}

		void addCourse(int hours,float grade) {
			average=semesterHours*average+grade;// 总分
			semesterHours+=hours;   // 总修学时
			average/=semesterHours; // 平均分
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
	// 研究生类（继承学生类）
	protected:
		Advisor advisor;    // 导师
		int qualifierGrade; // 资格考试分  
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
