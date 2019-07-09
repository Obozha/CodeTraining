#include<stdio.h>

int main(){
	int m,n,count=0,max=0;
	scanf("%d %d",&m,&n);
	for(;m<=n;m++){
		if(m%7==0&&m%4!=0){
			count++;
			if(max<m){
				max=m;
			}
		}
	}
	
	if(count==0){
		printf("no");
	}else{
		printf("%d",max);
	}
	return 0;
}
