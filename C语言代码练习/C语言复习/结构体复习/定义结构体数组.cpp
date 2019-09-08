#include<string.h>
#include<stdio.h>

struct Person{	// 声明结构体类型struct Person 
	char name[20]; // 候选人姓名 
	int count; // 候选人得票数 
}leader[3]={"Li",0,"Zhang",0,"Sun",0};

int main(){
	int i,j;
	char leader_name[20]; // 定义字符数组
	for(i=1;i<=10;i++){ // 输入候选人姓名 
		scanf("%s",leader_name);
		for(j=0;j<3;j++){
			if(strcmp(leader_name,leader[j].name)==0){
				leader[j].count++;				
			}
		}
	} 
	printf("\nResult:\n");
	for(i=0;i<3;i++){
		printf("%5s:%d\n",leader[i].name,leader[i].count);
	}
}
