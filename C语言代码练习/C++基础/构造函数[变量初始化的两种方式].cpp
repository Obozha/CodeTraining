#include<iostream>
#include<string.h>
using namespace std;

class Student{
    public:
       Student(char* pName="no name", int ssID=0)
         { //ð�ű�ʾ����Ҫ��������ݳ�Ա�Ĺ��캯�����е��á�
            //�����ǵ�����ssIDΪʵ�ε�StudentID���캯����
           cout <<"Constructing student " <<pName <<endl;
           strncpy(name,pName,sizeof(name));
           name[sizeof(name)-1]='\0';
          }
      protected:
            char name[20];
 };


int main(){
	int m=10; // ok
	int n(m*m); // TC++3.0������C++�±�׼����
	cout<<n;
	Student s="Jenny"; // ok
	Student t("Danny"); // ok
	 
}
