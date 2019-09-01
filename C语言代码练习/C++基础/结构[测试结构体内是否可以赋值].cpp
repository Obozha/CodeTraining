#include<iostream>
using namespace std;
struct Student{
	int number;
	char name[10];
	char sex;
	int age=10;
};

int main(){
	Student s;
	s.age=55;
	cout<<s.age<<endl;
}
