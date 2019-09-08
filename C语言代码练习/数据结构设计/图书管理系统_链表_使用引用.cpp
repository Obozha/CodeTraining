#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;
typedef struct LNode{
	ElemType data;         // ������ 
	struct LNode *next; // ָ����
}LNode,*LinkList;
// *LinkListΪLNode���͵�ָ��

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
		printf("����ռ�ʧ��");
	}
	L->data=0;
	L->next=NULL;
	return OK; 
}

Status ListInsert(LinkList L,int i,ElemType e){
	LinkList p=L;
	int j=0;
	while(p&&j<i-1){ // p��Ϊ�գ� ��i>0 
		p=p->next;
		j++;
	}
	if(!p||j>i-1){
		return ERROR; // Ѱ��i-1����� 
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
	// ��L����Ϊ�ձ�
	LinkList p,q;
	p=L->next; // pָ���һ�����
	while(p){
		q=p->next;
		free(p);
		p=q;
	} 
	L->next=NULL;
	return OK;
}

Status GetElem(LinkList L,int i,ElemType &e){
	LinkList p=L->next; // ���� 
	int j=1;
	while(p&&j<i){ // ���ɨ�裬ֱ��pָ���i��Ԫ�� ��pΪ�� 
		p=p->next;
		j++;
	}
	if(!p||j>i) //p��Ϊnull��i����С�ڵ���0 
		return ERROR;
	e=p->data;
	return OK;
}

Status ListDelete(LinkList L,int i){
	// ��ͷ���ĵ�����ɾ����i��Ԫ��
	LinkList p=L;
	int j=0;
	while((p->next)&&(j<i-1)){ // ���ҵ�i-1����㣬pָ��ý�� 
		p=p->next;
		j++;
	}
	if(!(p->next)||(j>i-1)){   // ��i>n����i<1ʱ��ɾ��λ�ò�����
	 	return ERROR;		
	}
	LNode* q=p->next;
	p->next=q->next;
	free(q);
	return OK; 
}

int ListLength(LinkList L){
	// ����L��Ԫ�ظ���
	LinkList p=L->next;
	int i=0;
	while(p){
		i++;
		p=p->next;
	}
	return i;
}

int isEmpty(LinkList L){
	// ���LΪ�ձ�ͷ���1�������򷵻�0 
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
	p=p->next; // ����ͷ�ڵ� 
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
//		printf("��Ϊ��"); 
//	} 
	
	BatchInsert(L);
	
	AccessNodeData(L);

	printf("����ĳ�����%d\n",ListLength(L));

	ElemType e=0;
	GetElem(L,3,e);
//	printf("%d",e);
	
	ListDelete(L,3);
	AccessNodeData(L);
//	ClearList(L);
//	
//	printf("%d",L->data);
//	if(L->next==NULL)
//		printf("�Ѿ�Ϊ�ձ�"); 
	
}

int main(){
	Unit();
}
