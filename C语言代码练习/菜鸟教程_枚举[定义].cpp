#include<stdio.h> // standard input & output 标准输入输出
enum DAY{
	MON = 1,TUE,WED,THU,FRI,SAT,SUM
}; // 省略枚举名称，直接定义枚举变量 

int main(){
	enum DAY day;
	day = WED;
	printf("%d",day);
	return 0;
}
