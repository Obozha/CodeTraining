#include<stdio.h>

int main(){
	int high,up,down,day=0,t=0;
	int mode=0;
	scanf("%d %d %d",&high,&up,&down);
	while(1){
		t+=up;	// 升高 
		if(t>=high){ 		// 	爬到比High高就跳出 
			day++; // 记得又是新的一天 
			break;
		}
		t-=down; // 晚上会滑 
		day++; 	// 一天过去了 
	}
	printf("%d",day);
	
} 
