#include<stdio.h>

int main(){
	int n,i;
//	printf("������������");
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
		
		// n���Ա�K��������Ӧ��ӡ��k��ֵ������n����k����
		// ��Ϊ�µ�������n���ظ�ִ�еڶ���
		// ���n���ܱ�k����������k+1��Ϊk��ֵ���ظ�ִ�е�һ�� 
	}
	printf("\n");
	return 0;
}
