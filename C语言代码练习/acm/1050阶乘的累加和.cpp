#include<stdio.h>
int getFactorial(int);
int main(){
	int i,n=0,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		sum+=getFactorial(i);
	}
	printf("%d",sum);
	return 0;
}

int getFactorial(int i){
	if(i==1){
		return 1;
	}else{
		return getFactorial(i-1)*i;
	}
}
