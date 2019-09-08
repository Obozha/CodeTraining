#include<iostream>
#include<string.h>
using namespace std;

class Student{
	public:
		Student(const char* pName){
			cout<<"constructing student"<<pName<<endl;
			strcpy(name,pName);
		} 
		~Student(){
			cout<<"destructing "<<name<<endl;
		}
		// 其他公共成员 
	protected:
		char name[20]; 
};

int main(){
	Student s1("Jenny");
	Student s2("Jone");
} 
