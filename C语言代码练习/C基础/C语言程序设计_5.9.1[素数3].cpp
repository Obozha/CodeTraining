#include<stdio.h>
#include<math.h>

int main(){
	int i,j,k;
	for(i=100;i<=200;i++){
		k=sqrt(i);
		for(j=2;j<=k;j++){
			if(i%j==0){
				break;
			}
		}
		if(j>k)
		//	printf("%d is not a prime\n",i);
			printf("%d is a prime\n",i);
	}
} 
