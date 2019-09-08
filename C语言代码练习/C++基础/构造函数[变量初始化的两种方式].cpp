#include<iostream>
#include<string.h>
using namespace std;

class Student{
    public:
       Student(char* pName="no name", int ssID=0)
         { //冒号表示后面要对类的数据成员的构造函数进行调用。
            //这里是调用以ssID为实参的StudentID构造函数。
           cout <<"Constructing student " <<pName <<endl;
           strncpy(name,pName,sizeof(name));
           name[sizeof(name)-1]='\0';
          }
      protected:
            char name[20];
 };


int main(){
	int m=10; // ok
	int n(m*m); // TC++3.0不允许，C++新标准允许
	cout<<n;
	Student s="Jenny"; // ok
	Student t("Danny"); // ok
	 
}
