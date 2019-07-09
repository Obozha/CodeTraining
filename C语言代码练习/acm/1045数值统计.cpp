#include<stdio.h>

int main(){
	int n,i,num,plusCount=0,minusCount=0,zeroCount=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num);
		if(num>0){
			plusCount++;
		}
		if(num==0){
			zeroCount++;
		}
		if(num<0){
			minusCount++;
		}
	}
	printf("%d %d %d",minusCount,zeroCount,plusCount);
	return 0;
}
