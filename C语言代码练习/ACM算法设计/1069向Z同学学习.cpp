#include<stdio.h>

int main(){
	int m,k,count=0;
	scanf("%d %d",&m,&k);
	
	while(m!=0){
		m--;
		count++;
		if(count%k==0){
			m++;
		}
	}
	printf("%d",count);
	return 0;
} 
