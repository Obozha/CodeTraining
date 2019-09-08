#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;
typedef int ElemType;
// ������Ĵ洢�ṹ 
typedef struct LNode{
	ElemType data;	    // ����������
	struct LNode *next; // ����ָ����  
}LNode,*LinkList;

int La_data[]={3,5,8,11};
int Lb_data[]={2,6,8,9,11,15,20};

Status InitList(LinkList &L){
	// ����һ���յĵ�����L
	L=(LinkList)malloc(sizeof(LNode)); 
	L->next=NULL;
	return OK;
} 

Status GetElem(LinkList L,int i,ElemType &e){
	LinkList p=L->next;
	int j=1; // ��ʼ����pָ����Ԫ��㣬������j����ֵΪ1
	while(p&&j<i){
		p=p->next; // p��ָ����һ�����
		j++;	   // ������j��Ӧ��1 
	}
	if(!p||j>i) // iֵ���Ϸ�i>��n��i<=0 
		return ERROR;
	e=p->data;
	return OK; 
}

LNode *LocateElem(LinkList L,ElemType e){
	// �ڴ�ͷ���ĵ�����L�в���ֵΪe��Ԫ��
	LinkList p=L->next; // ��ʼ����pָ����Ԫ���
	while(p&&p->data!=e)
		p=p->next;
	return p; 
}

Status ListInsert(LinkList &L,int i,ElemType e){
	// �ڴ�ͷ���ĵ�����L�е�i��λ�ò���ֵΪe���½��
	LinkList p=L;
	int j=0;
	while(p&&(j<i-1)) {
		p=p->next;
		j++;
	}
	if(!p||j>i-1)
		return ERROR;  // i>n+1����i<1
	LinkList s=(LinkList)malloc(sizeof(LNode));
	s->data=e;		 // �����*s����������Ϊe 
	s->next=p->next; // �����*s��ָ����ָ����ai
	p->next=s;
	return OK;
}

Status ListDelete(LinkList &L,int i){
	// �ڴ�ͷ���ĵ������У�ɾ����i��Ԫ��
	LinkList p=L;
	int j=0;
	while((p->next)&&(j<i-1)){ // ���ҵ�i-1����㣬pָ��� 
		p=p->next;
		j++;
	}
	if(p->next||j>i-1)
		return ERROR;
	LinkList q=p->next;
	p->next=q->next;
	free(q);
	return OK;
}

void MergeList_L(LinkList &LA,LinkList &LB,LinkList &LC){
	// ��֪������LA��LB��Ԫ�ذ�ֵ�ǵݼ�����
	LinkList pa=LA->next,pb=LB->next;
	LC=LA;
	LNode* pc=LC;
	while(pa&&pb){
		// LA��LB��δ�����β�����Ρ�ժȡ��������ֵ��С�Ľ�����LC�����
		if(pa->data<=pb->data){ //��ժȡ��pa��ָ��� 
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}else{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next=pa?pa:pb; // ���ǿձ��ʣ��β��뵽pc��ָ���֮��
	free(LB); 
}

void ResponseCode(Status Code) {
	switch(Code) {
		case OK:
			printf("Suc\n");
			break;
		case ERROR:
			printf("E\n");
			break;
		case OVERFLOW:
			printf("OVERFLOW\n");
			break;
		default:
			printf("No Status\n");
			break;
	}
}

void InitListData(LinkList L,int length,int data[]){
	int i;
	for(i=0;i<=length-1;i++){
		ListInsert(L,i+1,data[i]);
	}
}

void InitList_LA_LB(LinkList &LA,LinkList &LB){
	InitList(LA);
	InitList(LB);
	InitListData(LA,4,La_data);
	InitListData(LB,7,Lb_data);
}

void TraverList(LinkList L){
	LinkList p=L->next;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void Unit(){
	LinkList LA,LB,LC;
	InitList_LA_LB(LA,LB);
	TraverList(LA);
	TraverList(LB);
	MergeList_L(LA,LB,LC);
	TraverList(LC);
}

int main(){
	Unit();
}
