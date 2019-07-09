#include<stdio.h>

int main(){
	int n,i;
//	printf("请输入整数：");
	scanf("%d",&n);
//	printf("%d=",n);
	for(i=2;i<=n;i++){ // 20  
//		while(n%i==0){
//			printf("%d ",i);
//			n=n/i; 
////			if(n!=1)
////				printf("*"); 
//		}
		while(n%i==0){
			printf("%d ",i);
			n=n/i;	// i=2 n=10 i=2 n=5 i=5 
		}
		
		// n可以被K整除，则应打印出k的值，并用n除以k的商
		// 作为新的正整数n，重复执行第二步
		// 如果n不能被k整除，则用k+1作为k的值，重复执行第一步 
	}
	printf("\n");
	return 0;
}
