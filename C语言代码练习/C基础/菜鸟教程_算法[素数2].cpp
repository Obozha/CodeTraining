#include<stdio.h>
#include<math.h>


int main(){
	int i,j,k;

	printf("请输入数字:");
	scanf("%d",&j);
	k=(int)sqrt(j);
	
	for(i=2;i<=k;i++){
		if(j%i==0){
			break;
		}
	}
	if(i<=k)
		printf("%d不是素数",j);
	 else
		printf("%d是素数",j);	
} 
