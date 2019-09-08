#include<iostream>
#include<string.h>
using namespace std;

class Student {
	public:
	public:
		Student(const char* pName, int xHours, float xgpa) {
			cout <<"constructing student " <<pName <<endl;
			strncpy(name,pName,sizeof(name));
			name[sizeof(name)-1]='\0';
			semesHours=xHours;
			gpa=xgpa;
		}
	
		void Show(){
			cout<<name<<" "<<semesHours<<" "<<gpa<<endl;
		}
	
		~Student() {
			cout<<"destructing student "<<name<<endl;;
		}
		// 其他公共成员
	protected:
		char name[20];
		int semesHours;
		float gpa;

};

int  main( ) {
	Student ss("Jenny", 22, 3.5);
	ss.Show();
}

