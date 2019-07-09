#include<stdio.h>

int main(){
	int i,n;
	int sum;
	scanf("%d",&n);
	sum=1;
	for(i=2;i<=n;i++){
		sum=(sum+1)*2; // 当天的数量加1，乘2 得到前一天的数量 
	}
	printf("%d\n",sum);
	return 0;
}
