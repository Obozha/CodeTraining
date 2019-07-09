#include<stdio.h>

int main() {
	int n,i,m,result=1;
	
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d",&m);
			if(m%2!=0){
				result*=m;
			}
		}
		printf("%d\n",result);
		result=1;
	}

}
