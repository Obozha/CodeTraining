#include<iostream>
#include<string.h>

using namespace std;

class Student{
	public:
		Student(const char* pName);
		~Student();
		static Student* findname(const char* pName);
	protected:
		static Student *pFirst;
		Student* pNext;
		char name[40];
}; 

Student* Student::pFirst=0;
// ��̬��Ա�ռ���估��ʼ��
	strncpy(name,pName,sizeof(name));
	name[sizeof(name)-1]='\0';
	pNext=pFirst;
	pFirst=this;
} // ͷ�巨

Student::~Student(){
	if(pFirst==this){
		pFirst=pNext;
		return;
	}
	for(Student* pS=pFirst;pS;pS=pS->pNext){
		if(pS->pNext==this){
			pS->pNext=pNext;
			return;
		}
	}	
} 

Student* Student::findname(const char *pName){
	// ��̬��Ա����
	for(Student* pS=pFirst;pS;pS=pS->pNext)
		if(strcmp(pS->name,pName)==0){
			return pS;
		} 
	return NULL; // return (Student*)0;
}

int main(){
	Student s1("Randy");
	Student s2("Jenny");
	Student s3("Kinsey");
	Student *pS=Student::findname("Jenny");
	if(pS)
		cout<<"OK"<<endl;
	else
		cout<<"no find."<<endl;
	return 0;
}
