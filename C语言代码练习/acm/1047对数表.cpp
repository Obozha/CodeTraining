#include<stdio.h>
#include<math.h>

int main(){
	int i,n,num,output;
	scanf("%d",&i);
	scanf("%d",&n);
	for(;i<=n;i++){
		
		printf("%4d%8.4lf\n",i,log(i));
	}
} 
