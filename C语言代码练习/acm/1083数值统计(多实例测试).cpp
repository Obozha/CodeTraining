#include<stdio.h>

int main(){
	int n,i;
	float m;
	int  pCount=0,fCount=0,zCount=0;
	while(1){
		scanf("%d",&n);
		if(n==0){
			break;
		}
		for(i=0;i<n;i++){
			scanf("%f",&m);
			if(m>0){
				pCount++;
			}else if(m==0){
				zCount++;
			}else if(m<0){
				fCount++;
			}
		}
		printf("%d %d %d\n",fCount,zCount,pCount);
		fCount=0;
		zCount=0;
		pCount=0;
	}
		
}
