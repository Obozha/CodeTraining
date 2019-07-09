#include<stdio.h>

int main(){
	int i,n,num,sum=1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num);
		if(num%2!=0){
			sum*=num;
		}
	}
	printf("%d",sum);
	return 0;
} 
