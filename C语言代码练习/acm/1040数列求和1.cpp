#include<stdio.h>

int main(){
	int i,numerator=1,n,deno=1;
	double sum;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++,deno+=2){
		sum+=numerator/(double)deno;
	}
	printf("%.2lf",sum);
	return 0;
} 
