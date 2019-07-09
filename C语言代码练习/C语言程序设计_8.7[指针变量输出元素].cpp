#include<stdio.h>

int main(){
	int *p,i,a[10];
	p=a;
	printf("Please enter 10 integer number:");
	for(i=0;i<10;i++)
		scanf("%d",p++); // 执行完第一个for循环 p已经指向a数组的末尾
		
	// 解决这个问题的办法是 只要在第二个for循环之前加一个赋值语句 
	p=a; 
	for(i=0;i<10;i++,p++)
		printf("%d ",*p);
	printf("\n");
	return 0;
} 

// Error expected "要求"
// token "记号"

// [Error] expected ')' before ';' token 要求)前存在;记号 
// Line 行 Col 列 
