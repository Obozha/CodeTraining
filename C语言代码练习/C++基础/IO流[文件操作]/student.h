#include<iostream>
#include<string.h>
using namespace std;
#ifndef STUDENT
#define STUDENT

	class Student{ // 大学生类 
		protected:
			char pName[20];
			unsigned int UID;
			float grade;
		public:
			Student(char *pS,unsigned num,float g){
				strcpy(pName,pS);
				UID=num;
				grade=g;
			}
			
			virtual void display(ostream& out);
	};
	
	ostream& operator<<(ostream& out,Student& st);
	
#endif
