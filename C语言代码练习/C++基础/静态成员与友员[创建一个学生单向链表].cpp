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
	pNext=pFirst; // 每建立一个结点（对象），就将其挂在链首
	pFirst=this; 
} 

Student::~Student(){
	cout<<this->name<<endl;
	if(pFirst==this){ // 如果要删除链首结点，则只要链首指针指向下一个 
		pFirst=pNext;
		return;
	}
	for(Student *pS=pFirst;pS;pS=pS->pNext){
		if(pS->pNext=this){
			pS->pNext=pNext; // 找到时，pS指向当前结点的结点 
			return;			 // pNext即this->pNext 
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
