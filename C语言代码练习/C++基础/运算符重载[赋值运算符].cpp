#include<iostream>
#include<string.h>
using namespace std; 

class Name{
	protected:
		char* pName;
		void copyName(const char* pN);
		void deleteName();
	public:
		Name(){
			pName=0;
		}   // Ĭ�Ϲ��캯��
		
		Name(const char* pn){
			copyName(pn);
			// ���캯�� 
		} 
		
		Name(Name& s){
			copyName(s.pName);
			// �������캯�� 
		} 
		
		~Name(){
			deleteName();
		}
		
		Name& operator=(Name& s){ // ��ֵ����� 
			deleteName();
			copyName(s.pName);
			return *this;
		} 
		
		void display(){
			cout<<pName<<endl;
		}
}; 

void Name::copyName(const char* pN){
	pName=new char[strlen(pN)+1];
	if(pName){
		strcpy(pName,pN);
	}
}

void Name::deleteName(){
	if(pName){
		delete []pName;
		pName=0;
	}
}

int main(){
	Name s("caludette");
	Name t("temporary");
	Name a(s);
	a.display();
	t.display();
	t=s;	// ��ֵ 
	t.display();
}
