#include<stdio.h>

int main(){
	int i,numerator=1,deno=1,n=0;
	int f=1;
	
	
	double sum;
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++,deno+=2,numerator++){
		sum+=numerator/(double)deno*f;
		f=-f;
	}
	printf("%.3lf",sum);
	return 0;
}
