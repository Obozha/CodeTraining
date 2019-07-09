#include<stdio.h>
#include<math.h>

int main(){
	int input,i,k;
	
	printf("please enter a integer number:n= ");
	scanf("%d",&input);
	
	k=sqrt(input);
	
	for(i=2;i<=k;i++)
		if(input%i==0)
			break;
	if(i<=k){
		printf("%d 不是素数",input);
	}else{
		printf("%d 是素数",input); 
	}
}


//
//int isPrime(int n){ // 判断素数函数
//	int i;
//	for(i=2;i<=(int)sqrt(n);i++){
//		
//	} 
//}
