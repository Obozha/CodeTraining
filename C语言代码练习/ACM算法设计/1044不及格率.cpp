#include<stdio.h>

int main(){
	int i,n,num,count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num);
		if(num<60){
			count++;
		}
	}
	printf("%.2f",(double)count/n);
}
