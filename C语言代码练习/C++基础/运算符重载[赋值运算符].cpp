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
		}   // 默认构造函数
		
		Name(const char* pn){
			copyName(pn);
			// 构造函数 
		} 
		
		Name(Name& s){
			copyName(s.pName);
			// 拷贝构造函数 
		} 
		
		~Name(){
			deleteName();
		}
		
		Name& operator=(Name& s){ // 赋值运算符 
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
	t=s;	// 赋值 
	t.display();
}
