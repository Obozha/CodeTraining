#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;
typedef struct LNode{
	ElemType data;         // 数据域 
	struct LNode *next; // 指针域
}LNode,*LinkList;
// *LinkList为LNode类型的指针

Status InitList(LinkList &L);
Status ListInsert(LinkList L,int i,ElemType e);
Status ClearList(LinkList L);
Status DestoryList(LinkList L);
Status GetElem(LinkList L,int i,ElemType &e);

int ListLength(LinkList L);
int isEmpty(LinkList L);

void JudgeResponseCode(Status ResponseCode);
void BatchInsert(LinkList L);
void AccessNodeData(LinkList L);
void Unit();

Status InitList(LinkList &L){
	L=(LNode*)malloc(sizeof(LNode));
	if(L==NULL){
		printf("申请空间失败");
	}
	L->data=0;
	L->next=NULL;
	return OK; 
}

Status ListInsert(LinkList L,int i,ElemType e){
	LinkList p=L;
	int j=0;
	while(p&&j<i-1){ // p不为空， 切i>0 
		p=p->next;
		j++;
	}
	if(!p||j>i-1){
		return ERROR; // 寻找i-1个结点 
	}
	LNode *Node=(LNode*)malloc(sizeof(LNode));
	Node->data=e;
	Node->next=p->next;
	p->next=Node;
	return OK;
}

Status DestoryList(LinkList L){
	LinkList p;
	while(L){
		p=L;
		L=L->next;
		free(p);
	}
}

Status ClearList(LinkList L){
	// 将L重置为空表
	LinkList p,q;
	p=L->next; // p指向第一个结点
	while(p){
		q=p->next;
		free(p);
		p=q;
	} 
	L->next=NULL;
	return OK;
}

Status GetElem(LinkList L,int i,ElemType &e){
	LinkList p=L->next; // 跳过 
	int j=1;
	while(p&&j<i){ // 向后扫描，直到p指向第i个元素 或p为空 
		p=p->next;
		j++;
	}
	if(!p||j>i) //p不为null且i不能小于等于0 
		return ERROR;
	e=p->data;
	return OK;
}

Status ListDelete(LinkList L,int i){
	// 在头结点的单链表，删除第i个元素
	LinkList p=L;
	int j=0;
	while((p->next)&&(j<i-1)){ // 查找第i-1个结点，p指向该结点 
		p=p->next;
		j++;
	}
	if(!(p->next)||(j>i-1)){   // 当i>n或者i<1时，删除位置不合理
	 	return ERROR;		
	}
	LNode* q=p->next;
	p->next=q->next;
	free(q);
	return OK; 
}

int ListLength(LinkList L){
	// 返回L中元素个数
	LinkList p=L->next;
	int i=0;
	while(p){
		i++;
		p=p->next;
	}
	return i;
}

int isEmpty(LinkList L){
	// 如果L为空表就返回1，不是则返回0 
	if(L->next==NULL){
		return 1;
	}else{
		return 0;
	}
}

void JudgeResponseCode(Status ResponseCode){
	switch(ResponseCode){
		case OK:
			printf("Success\n");
			break;
		case ERROR:
			printf("ERROR check your code!\n");
			break;
		case OVERFLOW:
			printf("memory has OVERFLOW now\n");
			break;
		default:
			printf("No ResponseCode\n");
			break;
	}
}

void BatchInsert(LinkList L){
	JudgeResponseCode(ListInsert(L,1,15));
	JudgeResponseCode(ListInsert(L,2,16));
	JudgeResponseCode(ListInsert(L,3,22));
	JudgeResponseCode(ListInsert(L,4,23));
	JudgeResponseCode(ListInsert(L,5,55));
	JudgeResponseCode(ListInsert(L,6,66));
	JudgeResponseCode(ListInsert(L,7,12));
}

void AccessNodeData(LinkList L){
	LinkList p=L;
	p=p->next; // 跳过头节点 
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void Unit(){
	LinkList L;
	JudgeResponseCode(InitList(L));
	
//	if(isEmpty(L)==1){
//		printf("表为空"); 
//	} 
	
	BatchInsert(L);
	
	AccessNodeData(L);

	printf("数组的长度是%d\n",ListLength(L));

	ElemType e=0;
	GetElem(L,3,e);
//	printf("%d",e);
	
	ListDelete(L,3);
	AccessNodeData(L);
//	ClearList(L);
//	
//	printf("%d",L->data);
//	if(L->next==NULL)
//		printf("已经为空表"); 
	
}

int main(){
	Unit();
}
