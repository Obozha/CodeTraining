#include<stdio.h>

int main(){
	int n,i,k,j,m;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int result=0;
		scanf("%d",&k);
		for(j=0;j<k;j++){
			scanf("%d",&m);
			result+=m;
		}
		printf("%d\n",result);
	}
}
