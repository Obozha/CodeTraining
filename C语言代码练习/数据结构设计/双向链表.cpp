#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;	// ElemType 为可定义的数据类型，此设为int类型 
typedef int Status;		// status  是函数返回值类型，其值是函数结果状态代码 

struct Book{
	char id[50]; 		// ISBN
	char name[50]; 	// 书名
	double price;   // 定价 
};

typedef struct DuLNode{
	Book data;		// 数据域
	struct DuLNode *prior;  // 指向直接前驱 
	struct DuLNode *next;   // 指向直接后继 
}DuLNode,*DuLinkList;

int length;

Status InitList(DuLinkList &L){
	// 构造一个空的双向链表L 
	L=(DuLinkList)malloc(sizeof(DuLNode));
	L->prior=NULL; // 头节点的指针域置空 
	L->next=NULL;
	return OK;
}

DuLNode* GetElemP_DuL(DuLinkList L,int i){
	// 在带头结点的单链表L中根据序号i获取元素的值，用e返回L中第i个数据元素的值 
	int j=1;			
	DuLinkList p;
	p=L->next; // 初始化，p指向第一个结点，j为计数器 
	while(p&&j<i){	// 顺链域向后扫描，直到 p为空或p指向第i个元素 			
		p=p->next;		
		j++;		 
	}
	if(!p||j>i)
		return NULL; // 第i个元素不存在
	return p; 
} // GetElemP_Dul

Status ListInsert_DuL(DuLinkList L,int i,Book e){
	// 在带头结点的双向链表L中第i个位置之前 
	DuLinkList s,p;
	if(!(p=GetElemP_DuL(L,i))) // 在L中确定第i个元素的位置指针p
		return ERROR; 			   // p为NULL时，第i个元素不存在
	if(i==1){ // 在双向链表的第一个元素上插入
		s=(DuLinkList)malloc(sizeof(DuLNode));  // 生成新结点 
		s->data=e; 								// 将结点s数据置为e 
		DuLinkList p=L->next;
		L->next=s;
		s->prior=L;
		s->next=p; // 将结点*s插入L中
		p->prior=s;
		length++; 
	} 	
}

void ResponseCode(Status code){
	switch(code){
		case OK:
			printf("Success");
			break;
		case ERROR:
			printf("ERROR");
			break;
		case OVERFLOW:
			printf("OVERFLOW");
			break;
	}
}

void Unit(){
	DuLinkList L;
	ResponseCode(InitList(L));   // 初始化 
	
} 

int main(){
	Unit();
}

