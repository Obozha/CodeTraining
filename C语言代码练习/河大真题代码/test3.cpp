#include<iostream>
using namespace std;

class Date {
	private:
		int year;
		int month;
		int day;

	public:
		Date() {}
		Date(int y,int m,int d) {
			year=y;
			month=m;
			day=d;
		}
		Date NextDay();
		void Show() {
			cout<<year<<"-"<<month<<"-"<<day<<endl;
		}
	private:
		bool IsLeapYear();
};
Date Date::NextDay() {
	Date t;
	t.day=day;
	t.month=month;
	t.year=year;
	t.day++;
	if(IsLeapYear()) {
		if(t.month == 2 && day == 30) {
			t.day = 1;
			t.month++;
		}
	} else {        //???
		if(t.month == 2 && t.day == 29) {
			t.day=1;
			t.month++;
		}
	}
	if(t.day > 31) {
		if(t.month == 12) {
			t.day = 1;
			t.month = 1;
			t.year++;
		} else {
			t.day = 1;
			t.month++;
		}
	} else if(t.day == 31) {
		if(t.month==4||t.month==6||t.month==9||t.month==11) {
			t.day=1;
			t.month++;
		}
	}
	return t;
}

bool Date::IsLeapYear() {
	bool bleap;
	if((year%4 == 0 && year%100 != 0) || year%400 == 0)
		bleap = true;
	else
		bleap = false;
	return bleap;
}
 
int main() {
	int y,m,d;
	cout<<"printf the date:"<<endl;
	scanf("%d%d%d",&y,&m,&d);
	Date d1(y,m,d);
	Date d2;
	d2=d1.NextDay();
	d2.Show();
	system("pause");
	return 0;
}
