#include<iostream>
#include<string.h>
using namespace std;

class Student{
	public:
		Student(const char* pName);
		~Student();
	protected:
		char name[40];
		Student *pNext;
		static Student *pFirst;
};

Student* Student::pFirst=NULL; //0
Student::Student(const char *pName){
	strncpy(name,pName,sizeof(name));
	name[sizeof(name)-1]='\0';
	pNext=pFirst; // ÿ����һ����㣨���󣩣��ͽ����������
	pFirst=this; 
} 

Student::~Student(){
	cout<<this->name<<endl;
	if(pFirst==this){ // ���Ҫɾ�����׽�㣬��ֻҪ����ָ��ָ����һ�� 
		pFirst=pNext;
		return;
	}
	for(Student *pS=pFirst;pS;pS=pS->pNext){
		if(pS->pNext=this){
			pS->pNext=pNext; // �ҵ�ʱ��pSָ��ǰ���Ľ�� 
			return;			 // pNext��this->pNext 
		}
	}
}

Student *fn(){
	Student *pS=new Student("Jenny");
	Student sb("Jone");
	return pS;
}

int main(){
	Student sa("Jamsa");
	Student* sb=fn();
	Student sc("Tracey");
	delete sb;
	return 0; 
}
