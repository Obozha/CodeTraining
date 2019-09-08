#include<stdio.h>

int main(){
	int buyticket;
	scanf("%d",&buyticket);
	if(buyticket>=30){
		printf("%d",buyticket*48);
	}else{
		printf("%d",buyticket*50);
	}
	return 0;
}
