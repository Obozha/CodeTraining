#include<iostream>
using namespace std;

class Tdate{
	private:
		int month;
		int day;
		int year;
	public:
		void Set(int m,int d,int y){ // ������ 
			month=m;
			day=d;
			year=y;
		}
		int IsLeapYear(){ // �ж��Ƿ����� 
			return (year%4==0&&year%100!=0)||(year%400==0);
		}
		void Print(){ // �������ֵ 
			cout<<month<<"/"<<day<<"/"<<year<<endl;
		}
};

int main(){
	Tdate a;
	a.Set(2,4,1998);
	a.Print(); // ���н�� 2/4/1998 
} 
