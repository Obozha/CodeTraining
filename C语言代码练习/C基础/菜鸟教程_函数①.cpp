#include<stdio.h>
int main(){
	int a,b,result;
	int max(int num1,int num2);
	// int max(int,int) 在函数声明中，参数的名称并不重要 
	
	 
	printf("请输入两个数\n");
	scanf("%d,%d",&a,&b);
	result = max(a,b);
	printf("两者最大的数是:%d",result);
	return 0;
	
} 

/* 函数返回两个数中较大的那个数 */
int max(int num1,int num2){
	/* 局部变量声明 */
	int result;
	
	if(num1 > num2)
		result = num1;
	else
		result = num2;
	
	return result;
}
