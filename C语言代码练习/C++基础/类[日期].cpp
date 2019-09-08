#include<iostream>
using namespace std;

class Tdate{
	private:
		int month;
		int day;
		int year;
	public:
		void Set(int m,int d,int y){ // 置日期 
			month=m;
			day=d;
			year=y;
		}
		int IsLeapYear(){ // 判断是否闰年 
			return (year%4==0&&year%100!=0)||(year%400==0);
		}
		void Print(){ // 输出日期值 
			cout<<month<<"/"<<day<<"/"<<year<<endl;
		}
};

int main(){
	Tdate a;
	a.Set(2,4,1998);
	a.Print(); // 运行结果 2/4/1998 
} 
