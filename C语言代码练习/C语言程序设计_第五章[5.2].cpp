#include<stdio.h>

int main(){
	int i=1,sum=0;
	// 局部变量一定要先初始化 
	
	
	while(i<=100){
		sum+=i;
		i++;
	}
	
	printf("%d",sum);
	
}
