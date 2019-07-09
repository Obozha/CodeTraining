#include<stdio.h>
struct Student{
	int num;
	float score;
	struct Student *next; // next是指针变量，指向结构体变量 
}; 

int main(){
	struct Student a,b,c,*head,*p; // 定义3个结构体变量a.b,c作为链表的结点
	a.num=10101;
	a.score=89.5;
	b.num=10103;
	b.score=90;
	c.num=10107;
	c.score=85;
	head=&a;
	a.next=&b;
	b.next=&c;
	c.next=NULL;
	p=head;
	do{
		printf("%ld %5.1f\n",p->num,p->score); // 输出p指向的结点的数据
		p=p->next; // 使p指向下一个结点 
	}while(p!=NULL); // 输出完c结点后p的值为NULL，循环终止	
}
