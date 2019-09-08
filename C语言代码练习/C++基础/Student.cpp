#include<iostream>
#include<string.h>
#include"student.h"
using namespace std;
int Student::noOfStudents = 0;

Student::Student(char *pName){
	cout<<"create one student\n";
	strncpy(name,pName,40);
	name[39]='\0';
	noOfStudents++;
	cout<<noOfStudents<<endl;
	 
} 

Student::~Student(){
	cout<<"destruct one student\n";
	noOfStudents--;
	cout<<noOfStudents<<endl; 
}

int Student::number(){ //  
	return noOfStudents;
}
