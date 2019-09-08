#include<stdio.h>
#include<math.h>

int main(){
	int i,n=0;
	double item,sum;
	scanf("%lf %d",&item,&n);
	sum=item;
	if(item<10000&&n<1000)
		for(i=1;i<n;i++){
			sum+=sqrt(item);
			item=sqrt(item);
		}
	printf("%.2lf",sum);
	return 0;
} 
