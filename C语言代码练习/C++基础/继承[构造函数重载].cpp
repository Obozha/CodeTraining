#include<iostream>
#include<string.h> 
using namespace std;


class Student{
	public:
		Student(const char *pName){
			name=new char[40];
			strcpy(name,pName);
			name[39]='\0';
			n=0;
		}
		Student(int n){
			name=new char[40];
			this->n=n;
		} 
		void display(){
			cout<<n<<" "<<name<<endl;
		}
	protected:
		int n;
		char *name;
};

int main(){
	Student s1("HelloWorld"); 
	Student s2(3);
	s1.display();
	s2.display();
}
