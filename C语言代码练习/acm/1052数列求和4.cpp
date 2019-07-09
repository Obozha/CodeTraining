#include<stdio.h>

int main(){
	int item,i,n,a,sum=0;
	scanf("%d %d",&n,&a);
	
	item=0;
	
	if(n>=0&&n<10&&a<10&&a>=0){
		for(i=0;i<n;i++){	
			sum+=a;		// sum=2+22+222+2222
			item=item*10+a;
		}
		printf("%d",sum);
	}
	
	return 0;	
}
