#include<iostream>
using namespace std; 

class Tdate {
	public:
		Tdate(int m=4,int d=15,int y=1995) {
			month=m;
			day=d;
			year=y;
			cout<<month<<"/"<<day<<"/"<<year<<endl;
		}
	protected:
		int month;
		int day;
		int year;
};

int main() {
	Tdate  aday;
	Tdate  bday(2);
	Tdate  cday(3, 12);
	Tdate  dday(1, 2, 1998);

}
