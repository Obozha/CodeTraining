#include<stdio.h>

void printN_for(int n){ // 用for循环打出从1~N 
	int i;
	for(i=1;i<=n;i++){
		printf("%d\n",i);
	}
	return;
} 

void printN_rcs(int n){ // 用递归 
	if(n){
		printN_rcs(n-1);
		printf("%d\n",n);
	}
	return;
} 


int main(){
	printN_for(1000000); 
} 
 
