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
	weekend = (enum day)a;//����ת��
	printf("weekend:%d",weekend);
	return 0; 
}

//[Error] 'weekend' was not declared[���� ����] in this scope[��Χ]
// 
