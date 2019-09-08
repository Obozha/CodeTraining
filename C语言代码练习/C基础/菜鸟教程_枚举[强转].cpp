#include<stdio.h>
int main(){
	enum day{
		saturday,
		sunday,
		monday,
		tuesday,
		wesnesday,
		thursday,
		friday
	} workday;
	int a = 1;
	enum day weekend;
	weekend = (enum day)a;//类型转换
	printf("weekend:%d",weekend);
	return 0; 
}

//[Error] 'weekend' was not declared[宣布 声明] in this scope[范围]
// 
