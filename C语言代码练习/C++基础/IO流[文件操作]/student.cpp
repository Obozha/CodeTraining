#include<iomanip>
#include<iostream>
#include"student.h"

using namespace std; 

void Student::display(ostream& out){
	out<<setiosflags(ios::left)<<setw(20)<<pName<<UID<<","
	<<setiosflags(ios::right)<<setw(4)<<grade;
}

// ²åÈë²Ù×÷·û
ostream& operator<<(ostream& out,Student& st){
	st.display(out);
	out<<endl;
	return out;
} 


