#include<stdio.h>
#include<math.h>


int main(){
	int i,j,k;

	printf("����������:");
	scanf("%d",&j);
	k=(int)sqrt(j);
	
	for(i=2;i<=k;i++){
		if(j%i==0){
			break;
		}
	}
	if(i<=k)
		printf("%d��������",j);
	 else
		printf("%d������",j);	
} 
