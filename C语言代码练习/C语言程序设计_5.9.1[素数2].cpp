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
		printf("%d ��������",input);
	}else{
		printf("%d ������",input); 
	}
}


//
//int isPrime(int n){ // �ж���������
//	int i;
//	for(i=2;i<=(int)sqrt(n);i++){
//		
//	} 
//}
