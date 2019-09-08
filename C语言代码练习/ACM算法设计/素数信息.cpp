#include<stdio.h>
#include<math.h>
int calc(int);
int main(){
	int n;
	while(1){
		scanf("%d",&n);
		calc(n);
	}
}

int calc(int a){
	int i;
	for(i=2;i<=sqrt(a);i++){
		if(a%i==0){
			break;
		}
	}
	if(i<=sqrt(a)){
		printf("不是素数\n");
	}else{
		printf("是素数\n");
	}
}
