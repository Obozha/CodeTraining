#include<iostream>
using namespace std;

class Student{
	public:
		static char* sName(){
			// 静态成员函数是所有对象共享的
			cout<<noOfStudents<<endl;
			return name; // error那个对象？  
		}	
	protected:
		char name[40];
		static int noOfStudents;
}; 
