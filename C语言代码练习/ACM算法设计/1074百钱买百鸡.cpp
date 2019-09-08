#include<stdio.h>

#define TRUE 1
#define FALSE 0

int main(){
	int x,y,z,n,noAnswer;
	scanf("%d",&n);
	noAnswer=TRUE;
	for(x=0;x<=n/5;x++){ //穷举公鸡个数 
		for(y=0;y<=n/3;y++){
			z=n-x-y; //其余是鸡仔
			if(15*x+9*y+z==n*3){
				printf("%4d%4d%4d\n", x, y, z);
				noAnswer=FALSE;
			} 
		}
	}
	if(noAnswer==TRUE){
		printf("No Answer\n");
	}
	return 0;
} 
