#include<stdio.h>

int main(){
	int high,up,down,day=0,t=0;
	int mode=0;
	scanf("%d %d %d",&high,&up,&down);
	while(1){
		t+=up;	// ���� 
		if(t>=high){ 		// 	������High�߾����� 
			day++; // �ǵ������µ�һ�� 
			break;
		}
		t-=down; // ���ϻỬ 
		day++; 	// һ���ȥ�� 
	}
	printf("%d",day);
	
} 
