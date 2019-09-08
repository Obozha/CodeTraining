#include<stdio.h>

int main(){
	int i,n,k;
	double result=0; // ³õÊ¼ÖµÎª0 
	scanf("%d",&k);
	for(i=1;;i++){
		if(result>k){
			break;
		}
		result+=1.0/i;
	}
	printf("%d",i);
}
