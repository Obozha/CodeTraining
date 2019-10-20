#include "stdio.h"

int IsLeapYear(int Year);//�ж��ǲ������ꡣ
int IsCurrentDate(int Year,int Month,int Day);//�ǲ�����ȷ�����ڡ�
int ReturnNextDay(int Year,int Month,int Day);//������һ�죬Ҳ���ж��ǲ�����ȷ�����ڡ�
int LeapYear_Month_SumDay[12]= {31,29,31,30,31,30,31,31,30,31,30,31}; //�������飬�������������

int main() {
	int Year=0,Month=0,Day=0,NextDay=0;
	printf("pleace enter right Date(example:2005 6 27):\n");
	scanf("%d%d%d",&Year,&Month,&Day);
	NextDay=ReturnNextDay(Year,Month,Day);

	switch (NextDay) {
		case 0:
			printf("not a current date\n");
			break;
		case 1:
			if (Month==12) {
				Year++;
				Month=1;
			} else {
				Month++;
			}
			break;
	}
	if (NextDay!=0) printf("The you input next date is %d-%d-%d.Thank use bye bye!\n",Year,Month,NextDay);

}

int IsLeapYear(int Year) {
	if (Year%4==0) {
		if (Year%400) return 1;
		else {
			if (Year%100==0) return 0;
			else return 1;
		}
	} else {
		return 0;
	}
}

int IsCurrentDate(int Year,int Month,int Day) {
	if ((Year<0) && (Year>9999) && (Month>12) && (Month<1) && (Day<1) &&(Day>31) )
		return 0;
	else 
		return 1;
}

int ReturnNextDay(int Year,int Month,int Day) {
	int ThisMonthSumDay;
	if (IsCurrentDate(Year,Month,Day)==1) { // �ж�������д�Ƿ���ȷ 
		ThisMonthSumDay=LeapYear_Month_SumDay[Month-1]; // �����긳ֵ 
		if (Month==2) {
			if (IsLeapYear(Year)==0) ThisMonthSumDay--;
		}
		
		if (Day<ThisMonthSumDay) {
			return ++Day;
		} else {
			if (Day==ThisMonthSumDay) {
				return 1;
			} else {
				return 0;
			}

		}
	} else {
		return 0;
	}
}
