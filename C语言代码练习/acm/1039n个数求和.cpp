#include<stdio.h>

int main(){
	int i,n;
	int sum=0,number;
	
	scanf("%d",&n); // ����һ������n 
	
	for(i=1;i<=n;i++){ // ����n���� 
		scanf("%d",&number);
		sum+=number; // ���������� 
	}
	printf("%d",sum);
	return 0;
}
