#include<iostream>
using namespace std;
int month; // ȫ�ֱ���
int day;
int year;
void Set(int m,int d,int y) { // �ǳ�Ա����
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
		void Set(int m,int d,int y) { // ������
			month=m;
			day=d;
			year=y;
			::Set(m,d,y); // ���÷ǳ�Ա����
		}
		int IsLeapYear() { // �ж��Ƿ�����
			return (year%4==0&&year%100!=0)||(year%400==0);
		}
		void Print() { // �������ֵ
			cout<<month<<"/"<<day<<"/"<<year<<endl;
		}
};

