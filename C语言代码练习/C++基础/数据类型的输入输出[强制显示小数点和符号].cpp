#include<iostream>
#include<iomanip> // Ҫ�õ���ʽ���Ʒ�
using namespace std;

int main() {
	cout <<10.0/5 <<endl;  //2
	cout <<setiosflags(ios::showpoint)
	     <<10.0/5 <<endl;  //2.00000

	cout <<10 <<"  "<<-20 <<endl; //10 -20
	cout <<setiosflags(ios::showpos)
	     <<10 <<"  "<<-20 <<endl; //+10 -20

}
