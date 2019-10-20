#include<iostream>
using namespace std;

class Date {
	private:
		int mYear;
		int mMonth;
		int mday;
	public:
		void AddYear() {
			mYear++;
		}

		void SetDate(int Year, int Month,int Day) {
			if(IsCurrentDate(Year,Month,Day)){
				mYear=Year;
				mMonth=Month;
				mday=day;
			} 
		}

		int IsCurrentDate(int Year,int Month,int Day) {
			if ((Year<0) && (Year>9999) && (Month>12) && (Month<1) && (Day<1) &&(Day>31) )
				return 0;
			else
				return 1;
		}
};
