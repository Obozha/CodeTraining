#include<stdio.h>
enum DAY{
	MON=1,TUE,WED,THU,FRI,SAT,SUN
} day;

int main(){
	// 遍历枚举元素
	for(day=MON;day<=SUN;(int)day++){
		printf("枚举元素:%d\n",day);
	} 
} 
//[Error] no 'operator++(int)' declared for postfix '++' [-fpermissive] 
// 把文件后缀改为c就可以用了 
