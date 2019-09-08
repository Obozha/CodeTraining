#include<stdio.h>

int main(){
	int n,i,num;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%*6d%5d",&num);
		printf("6%05d\n",num);
	}
} 
