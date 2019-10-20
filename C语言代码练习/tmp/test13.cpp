#include<iostream>
#include<string.h>
using namespace std;

typedef struct student{
	int id=0;
	char name[10];
}stu; 

int main(){
	stu s;
	s.id=0; 
	strcpy(s.name,"HelloW");
	cout<<s.id<<" "<<s.name;
}
