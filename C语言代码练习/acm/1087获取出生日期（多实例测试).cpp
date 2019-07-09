#include<stdio.h>

int main(){
	int y,m,a,n,i;	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%*6d%4d%2d%2d%*d",&y,&m,&a);
		printf("%d-%02d-%02d\n",y,m,a);
	}
	return 0;
} 
