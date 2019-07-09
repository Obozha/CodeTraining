#include<stdio.h>

int main(){
	float f;
	scanf("%f",&f);
	if(f>=5000){
		printf("%.2f",f-(f*(1-0.8)));
	}else if(f>=3000){
		printf("%.2f",f-(f*(1-0.85)));
	}else if(f>=1000){
		printf("%.2f",f-(f*(1-0.9)));
	}else if(f>=500){
		printf("%.2f",f-(f*(1-0.95)));
	}else{
		printf("%.2f",f);
	}
}
