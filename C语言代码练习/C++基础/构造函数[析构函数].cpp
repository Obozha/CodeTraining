#include<iostream>
using namespace std;

class Student {
	public:
		Student() {
			cout<<"constructing student.\n";
			semesHours=100;
			gpa=3.5;
		}
		~Student() {
			cout<<"destructing student.\n";
		}
		// 其他公共成员
	protected:
		int semesHours;
		float gpa;
};

class Teacher {
	public:
		Teacher( ) {
			cout <<"constructing teacher.\n";
		}
		~Teacher( ) {
			cout <<"destructing teacher.\n";
		}		
};

class TutorPair {
	public:
		TutorPair( ) {
			cout <<"constructing tutorpair.\n";
			noMeetings=0;
		}
		~TutorPair( ) {
			cout <<"destructing tutorpair.\n";
		}
	protected:
		Student student;
		Teacher teacher;
		int noMeetings;
};

int  main(  ) {
	TutorPair tp;
	cout <<"back in main.\n";
}

