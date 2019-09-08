#include<iostream>
using namespace std;
int month; // 全局变量
int day;
int year;
void Set(int m,int d,int y) { // 非成员函数
	month=m;
	day=d;
	year=y;
}

class Tdate {
	private:
		int month;
		int day;
		int year;
	public:
		void Set(int m,int d,int y) { // 置日期
			month=m;
			day=d;
			year=y;
			::Set(m,d,y); // 调用非成员函数
		}
		int IsLeapYear() { // 判断是否闰年
			return (year%4==0&&year%100!=0)||(year%400==0);
		}
		void Print() { // 输出日期值
			cout<<month<<"/"<<day<<"/"<<year<<endl;
		}
};

