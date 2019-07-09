#include<stdio.h>

int main(){
	int i,n;
	int sum=0,number;
	
	scanf("%d",&n); // 输入一个整数n 
	
	for(i=1;i<=n;i++){ // 输入n个数 
		scanf("%d",&number);
		sum+=number; // 边输入边求和 
	}
	printf("%d",sum);
	return 0;
}
