#include <iostream>
#include <string.h>
using namespace std;
class Person {
	public:
		Person(char* pN);
		Person(Person& p);
		~Person( );
	protected:
		char* pName;
};
Person::Person(char* pN) {
	cout <<"Constructing " <<pN <<endl;
	pName=new char[strlen(pN)+1];
	if(pName!=0) strcpy(pName, pN);
}
Person::Person(Person& p) {
	cout <<"Copying " <<p.pName
	     <<" into its own block\n";
	pName=new char[strlen(p.pName)+1];
	if(pName!=0)  strcpy(pName, p.pName);
}
Person::~Person( ) {
	cout <<"Destructing " <<pName <<endl;
	pName[0]='\0';
	delete []pName;
}

int main( ) {
	Person p1("Randy");
	Person p2=p1;       //��Person p2(p1);
}

