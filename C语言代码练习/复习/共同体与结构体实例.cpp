#include<stdio.h>

struct{	// 声明无名结构体类型
	int num;	 
	char name[10];	
	char sex;
	char job;
	union{
		int claz;
		char position[10]; 
	}category;
} person[2]; 

int main(){
	int i;
	for(i=0;i<2;i++){
		printf("please enter the data of person:\n");
		scanf("%d %s %c %c",&person[i].num,&person[i].name,&person[i].sex,&person[i].job);
		if(person[i].job=='s'){
			scanf("%d",&person[i].category.claz);
		}else if(person[i].job=='t')
			scanf("%s",person[i].category.position);
		else
			printf("Input error!");
	}
	printf("\n");
	printf("No namesex job class/position\n");
	for(i=0;i<2;i++){
		if(person[i].job='s')
			printf("%-6d%-10s%-4c%-4c%-10d%\n",person[i].num,person[i].sex,person[i].job,person[i].category.claz);
		else
			printf("%-6d%-10s%-4c%-4c%-10s%\n",person[i].num,person[i].sex,person[i].job,person[i].category.position);
	}
	return 0;
}	
