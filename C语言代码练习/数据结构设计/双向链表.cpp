#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;	// ElemType Ϊ�ɶ�����������ͣ�����Ϊint���� 
typedef int Status;		// status  �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���� 

struct Book{
	char id[50]; 		// ISBN
	char name[50]; 	// ����
	double price;   // ���� 
};

typedef struct DuLNode{
	Book data;		// ������
	struct DuLNode *prior;  // ָ��ֱ��ǰ�� 
	struct DuLNode *next;   // ָ��ֱ�Ӻ�� 
}DuLNode,*DuLinkList;

int length;

Status InitList(DuLinkList &L){
	// ����һ���յ�˫������L 
	L=(DuLinkList)malloc(sizeof(DuLNode));
	L->prior=NULL; // ͷ�ڵ��ָ�����ÿ� 
	L->next=NULL;
	return OK;
}

DuLNode* GetElemP_DuL(DuLinkList L,int i){
	// �ڴ�ͷ���ĵ�����L�и������i��ȡԪ�ص�ֵ����e����L�е�i������Ԫ�ص�ֵ 
	int j=1;			
	DuLinkList p;
	p=L->next; // ��ʼ����pָ���һ����㣬jΪ������ 
	while(p&&j<i){	// ˳�������ɨ�裬ֱ�� pΪ�ջ�pָ���i��Ԫ�� 			
		p=p->next;		
		j++;		 
	}
	if(!p||j>i)
		return NULL; // ��i��Ԫ�ز�����
	return p; 
} // GetElemP_Dul

Status ListInsert_DuL(DuLinkList L,int i,Book e){
	// �ڴ�ͷ����˫������L�е�i��λ��֮ǰ 
	DuLinkList s,p;
	if(!(p=GetElemP_DuL(L,i))) // ��L��ȷ����i��Ԫ�ص�λ��ָ��p
		return ERROR; 			   // pΪNULLʱ����i��Ԫ�ز�����
	if(i==1){ // ��˫������ĵ�һ��Ԫ���ϲ���
		s=(DuLinkList)malloc(sizeof(DuLNode));  // �����½�� 
		s->data=e; 								// �����s������Ϊe 
		DuLinkList p=L->next;
		L->next=s;
		s->prior=L;
		s->next=p; // �����*s����L��
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
	ResponseCode(InitList(L));   // ��ʼ�� 
	
} 

int main(){
	Unit();
}

