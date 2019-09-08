#include<stdio.h>
#include<math.h>

int i,j;

int main(){
	printf("请输入数字:");
	scanf("%d",&j);
	for(i=2;i<j;i++){
		if(j%i==0){
			break;
		}
	}
	if(i<j)
		printf("%d不是素数",j);
	 else
		printf("%d是素数",j);
	
	
	
} 
