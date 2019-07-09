#include<stdio.h>
#include<limits.h>

int main(){
	int n,i,num;
	scanf("%d",&n);
	
	int max=INT_MIN;
	for(i=0;i<n;i++){
		scanf("%d",&num);
		if(num>max){
			max=num;
		}
	}
	printf("%d",max);
}
