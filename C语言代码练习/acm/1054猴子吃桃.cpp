#include<stdio.h>

int main(){
	int i,n;
	int sum;
	scanf("%d",&n);
	sum=1;
	for(i=2;i<=n;i++){
		sum=(sum+1)*2; // �����������1����2 �õ�ǰһ������� 
	}
	printf("%d\n",sum);
	return 0;
}
