#include<iostream>
using namespace std;

class Student{
	public:
		Student(){
			cout<<"constructing student.\n";
			semesHours=100;
			gpa=3.5;
		}
	protected:
		int semesHours;
		float gpa;
};

class Teacher{
	public:
		Teacher(){
			cout<<"constructing teacher.\n";		
		}
};

class TutorPair {
		
	public:
		TutorPair(){
			cout<<"constructing tutorpair.\n";
			noMeetings=0; 
		}
		protected:
			Student student;
			Teacher teacher;
			int noMeetings; // »áÎî´ÎÊý 
};


int main() {
	      TutorPair  tp;
     cout <<"back in main.\n";

		
}
