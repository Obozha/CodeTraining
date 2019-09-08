#include <iostream>
#include <string.h>

using namespace std;
class Student {
	private:
		char name[40];
		int  id;
	public:
		Student(char* pName="no name", int ssId=0) {
			id = ssId;
			strcpy(name,pName);
			cout <<"Constructing new student "
			     <<pName <<endl;
		}
		Student(Student& s) { //¿½±´¹¹Ôìº¯Êý
			cout <<"Constructing copy of "<<s.name <<endl;
			strcpy(name,"copy of ");
			strcat(name, s.name);
			id=s.id;
		}
		~Student( ) {
			cout <<"Destructing " <<name <<endl;
		}
};
void fn(Student s1) {
	cout <<"In function fn()\n";
}
int main() {
	Student randy("Randy",1234);
	cout <<"Calling fn()\n";
	fn(randy);
	cout <<"Returned from fn()\n";
}

