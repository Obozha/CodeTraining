#include<stdio.h>

int getFactorial(int i);

int main(){
	int n=0,i;
	double sum=0;
	scanf("%d",&n);
	
	for(i=1;;i++){			// warmming!!! i²»¿ÉÒÔ=0 
		sum+=getFactorial(i);
		if(sum>=n){
			printf("m<=%d\n",i-1);
			break;
		}
	}
	return 0;
}

int getFactorial(int i){
	if(i==0){
		return 1;
	}
	if(i==1)
		return 1;
	else
		return i*getFactorial(i-1);
} 
