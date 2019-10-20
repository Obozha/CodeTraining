#include<iostream>
using namespace std;

// һ�����߰�ʮ������ʮһ������������Ŷ���ʮ�죬ƽ����¶�ʮ�ˣ�
int LeapCurrentMonthSumDays[]= {
	31,28,31,30,31,30,31,31,30,31,30,31
};

class Date {
	private:
		int Year;
		int Month;
		int Day;
		int CurrentMonthSumDay;
	public:
		Date() {
			Year=1000;
			Month=1;
			Day=1;
		};
		void Display();
		int IsLeap(int Year);
		void AddDay();
		void SetDate(int Year,int Month,int Day);
};

void Date::SetDate(int Year,int Month,int Day) {
	if(Year<=9999&&Year>=1&&Month>=1&&Month<=12&&Day>=1&&Day<=31) {
		CurrentMonthSumDay=LeapCurrentMonthSumDays[Month-1];
		if(IsLeap(Year)) {
			CurrentMonthSumDay++;
		}
		if(Day<=CurrentMonthSumDay) {
			this->Day=Day;
			this->Year=Year;
			this->Month=Month;
		} else {
			cout<<"����ʧ��"<<endl;
		}
	} else {
		cout<<"����ʧ��"<<endl;
	}
}

void Date::Display() {
	cout<<"��ǰʱ��Ϊ��"<<Year<<"��"<<Month<<"��"<<Day<<"��"<<endl;
}

int Date::IsLeap(int Year) {
	if(Year%400==0||(Year%4==0&&Year%100!=0)) {
		// (i%4==0&&i%100!=0)||i%400==0
		return 1;
	} else {
		return 0;
	}
}

void Date::AddDay() {
	CurrentMonthSumDay=LeapCurrentMonthSumDays[Month-1];
	int flag;
	if(Month==2&&IsLeap(this->Year)) {
		CurrentMonthSumDay++;
	}
	if(Day<CurrentMonthSumDay) {
		Day++;
	} else {
		if(Day==CurrentMonthSumDay) {
			flag=1;
		} else {
			flag=0;
		}
	}
	if(flag==1) {
		Day=1;
		if(Month==12) {
			Year++;
			Month=1;
		} else {
			Month++;
		}
//		cout<<"���ӳɹ�"<<endl;
	}
}

int main() {
	int Year,Month,Day;
	Date d;
	cout<<"�����������գ�";
	cin>>Year>>Month>>Day;
	d.SetDate(Year,Month,Day);
	d.AddDay();
	d.Display();
}
