#include<stdio.h> // standard input & output ��׼�������
enum DAY{
	MON = 1,TUE,WED,THU,FRI,SAT,SUM
}; // ʡ��ö�����ƣ�ֱ�Ӷ���ö�ٱ��� 

int main(){
	enum DAY day;
	day = WED;
	printf("%d",day);
	return 0;
}
