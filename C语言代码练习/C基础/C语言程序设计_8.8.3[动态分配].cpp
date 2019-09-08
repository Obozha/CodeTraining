#include<stdio.h>
#include<stdlib.h>

int main(){
	void check(int*); // 函数声明
	int *p1,i;
	p1=(int *)malloc(5*sizeof(int)); // 开辟动态内存区，将地址转换成int* 型，然后放在p1中
	for(i=0;i<5;i++){
		scanf("%d",p1+i);	// 输入5个学生成绩
	} 
	check(p1); // 调用check函数
	return 0; 
} 

void check(int *p){ // 定义check函数，形参是int *指针 
	int i;
	printf("They are fail:");
	for(i=0;i<5;i++){
		if(p[i]<60){
			printf("%d ",p[i]); // 输出不合格的成绩 
		}
	}
	printf("\n");
}
