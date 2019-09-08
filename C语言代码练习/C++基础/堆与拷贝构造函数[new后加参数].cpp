#include<iostream>
using namespace std;

class Student{
	public:
		Student(int m){
			cout<<m<<endl;;
		}
};

int main(){
	Student* s=new Student(15);
//	Student* Ps=new Student[10]; 
}
