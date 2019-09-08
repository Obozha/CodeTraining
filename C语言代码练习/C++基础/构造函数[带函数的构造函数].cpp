#include<iostream>
#include<string.h> 
using namespace std; 

class Student {
	public:
		Student(const char* pName) {
			cout<<"constructing student "<<pName<<endl;
			strncpy(name,pName,sizeof(name)); // 字符串赋值
			name[sizeof(name-1)]='\0'; 
		}
		~Student() {
			cout<<"destructing student "<<name<<endl;;
		}
		// 其他公共成员
	protected:
		char name[20];
};

int  main( ) {
	Student ss("Jenny");
	Student ss1("XiaoMing");
}
 
