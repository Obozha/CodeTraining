#include<stdio.h>
#include<math.h>

int i,j;

int main(){
	printf("����������:");
	scanf("%d",&j);
	for(i=2;i<j;i++){
		if(j%i==0){
			break;
		}
	}
	if(i<j)
		printf("%d��������",j);
	 else
		printf("%d������",j);
	
	
	
} 
