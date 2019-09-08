#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct Student)
struct Student{		// 声明结构体类型struct Student 
	long num;
	float score;
	struct Student *next;
};

int n;	// 全局变量n
void print(struct Student* head){ // 定义print函数 
	struct Student* p;	// 在函数中定义struct Student类型的变量p
	printf("\nNow,These %d records are:\n",n); 
	p=head;
	if(head!=NULL){
		do{
			printf("%ld %5.1f\n",p->num,p->score);
			p=p->next; 
		}while(p!=NULL); //当p不是"空地址" 
	}
} 
