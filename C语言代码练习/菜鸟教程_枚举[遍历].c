#include<stdio.h>
enum DAY{
	MON=1,TUE,WED,THU,FRI,SAT,SUN
} day;

int main(){
	// ����ö��Ԫ��
	for(day=MON;day<=SUN;(int)day++){
		printf("ö��Ԫ��:%d\n",day);
	} 
} 
//[Error] no 'operator++(int)' declared for postfix '++' [-fpermissive] 
// ���ļ���׺��Ϊc�Ϳ������� 
