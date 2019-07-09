#include<stdio.h>
#include<math.h> 

int main(){
	int x;
	scanf("%d",&x);
	if(x<-2){
		printf("%d",7-2*x);
	}else if(x>=-2&&x<3){
		if((3*x+2)>=0){
			printf("%d",5-(3*x+2));
		}else{
			printf("%d",5-(-(3*x+2)));
		}
	}else if(x>=3){
		printf("%d",3*x+4);
	}
}
