#include<iostream>
#include<string.h>
using namespace std;
class Student {
	protected:
		static int noOfStudents;
		char name[40];
	public:
		Student(char *pName="no name") {
			cout<<"create one student\n";
			strncpy(name,pName,40);
			name[39]='\0';
			noOfStudents++;
			// ��̬��Ա��û����һ������ѧ��������1
			cout<<noOfStudents<<endl;
		}
		~Student() {
			cout<<"destruct one student\n";
			noOfStudents--;
			// ÿ����һ������ѧ��������1
			cout<<noOfStudents<<endl;
		}
		static int number() { // ��̬��Ա����
			return noOfStudents;
		}
};

int Student::noOfStudents=0;
// ��̬���ݳ�Ա���������ռ�ͳ�ʼ�� 

void fn(){
	Student s1;
	Student s2;
	cout<<Student::number()<<endl;
	// ���þ�̬��Ա�������������� 
}

int main(){
	fn();
	cout<<Student::number( ) <<endl;
	// ���þ�̬��Ա��������������
	return 0; 
} 

