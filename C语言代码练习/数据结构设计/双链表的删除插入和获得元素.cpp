#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;   // Status   �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬����
typedef int ElemType; // ElemType Ϊ�ɶ�����������ͣ�����Ϊint����
int length=0;

struct Book {
	char id[50]; 	  // ISBN
	char name[50];  // ����
	double price; // ����
};

typedef struct DuLNode {
	Book data;    			// ������
	struct DuLNode *prior;   // ֱ��ǰ��
	struct DuLNode *next;   // ֱ�Ӻ��
} DuLNode,*DuLinkList;

Status InitDuList_L(DuLinkList &L) {
	// ����һ���յ�˫���б�L
	L=(DuLinkList)malloc(sizeof(DuLNode));	// �����½����Ϊͷ�ڵ㣬��ͷָ��Lָ��ͷ���
	L->next=NULL;  // ͷ����ָ�����ÿ�
	L->prior=NULL;
	return OK;
}

DuLNode *GetElemP_DuL(DuLinkList L,int i) {
	// �ڴ�ͷ����˫�������в��ҵ�i��Ԫ�أ����ؽ��ĵ�ַ
	DuLinkList p=L->next;
	int j=1;		// ��ʼ����pָ���һ����㣬jΪ������
	while(j<i&&p) {	// ˳�������ɨ�裬ֱ��pָ���i��Ԫ�ػ�pΪ��
		p=p->next;
		j++;
	}
	if(!p||j>i)		 // ˵��i<1 i����<=0
		return NULL; // ��i��Ԫ�ز�����
	return p;
}

Status ListInSert_DuL(DuLinkList &L,int i,Book e) {
	DuLinkList s,p;
	if(!(p=GetElemP_DuL(L,i))) {
		if(!(((i==1)&&(L->next))||(i==length+1))) {
			return ERROR;
		}
	}
	if((i==1)&&(L->next==NULL)) { // ��˫������ĵ�һ��Ԫ���ϲ���
		s=(DuLinkList)malloc(sizeof(DuLNode)); // �����½��s
		s->data=e;
		s->next=NULL;
		DuLinkList p=L;
		L->next=s;
		s->prior=L;
		length++;
	} else if(i==1) { // ��˫������ĵ�һ��Ԫ�ز���
		s=(DuLinkList)malloc(sizeof(DuLNode)); // �����½��s
		s->data=e; // �����s������Ϊe
		DuLinkList p=L->next;
		L->next=s;
		s->prior=L;
		s->next=p;
		p->prior=s;
		length++;
	} else if(i==length+1) {
		s=(DuLinkList)malloc(sizeof(DuLNode));
		s->data=e;
		p=L;
		while(p->next){
			p=p->next;
		}
		p->next=s;
		s->prior=p;
		s->next=NULL;
		length++;
	} else {
		s=(DuLinkList)malloc(sizeof(DuLNode));
		s->data=e;
		s->prior=p->prior;
		p->prior->next=s;
		s->next=p;
		p->prior=s;
		length++;
	}
}

Status SuperInsert(DuLinkList &L,int i,const char*name,const char* id,double price){
	Book b;
	strcpy(b.id,id);
	strcpy(b.name,name);
	b.price=price;
	if(ListInSert_DuL(L,i,b)==OK){
		return OK;
	}
}

Status ListDelete_DuL(DuLinkList &L,int i){ 
	// ɾ����ͷ����˫������L�е�iλ��֮ǰ����Ԫ��e��i�ĺϷ�ֵΪi<=i<=��
	DuLinkList p;
	if(!(p=GetElemP_DuL(L,i))) { // ��L��ȷ����i��Ԫ�ص�λ��ָ��p 
		return ERROR;	// pΪNULLʱ����i��Ԫ�ز�����  
	}
	if(i==1) {
		L=L->next;	// ֱ�Ӱ���һ����㵱��ͷ���������ɾ����һ����� 
		return OK;
	} else if(i==length){ // 
		p->prior->next=NULL;
		free(p);
		length--;
		return OK;
	} else{
		p->prior->next=p->next; 
		p->next->prior=p->prior;
		free(p);
		length--;
		return OK;
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

void TraverseList(DuLinkList L){
	DuLinkList p=L->next;
	while(p){
		printf("ID:%s ����:%s �۸�:%.0lf \n",p->data.id,p->data.name,p->data.price);
		p=p->next;
	}
}

void CreateDuList_L(DuLinkList &L){
	// ��λ������n��Ԫ�ص�ֵ����������ͷ����˫������L��ͬʱ����ǰ��ָ��
	 DuLinkList r,p;
}

void BatchInsertInto(DuLinkList &L){
	SuperInsert(L,1,"JAVA","1234",10);
	SuperInsert(L,2,"C","1235",10);
	SuperInsert(L,3,"Python","1236",10) ;
	SuperInsert(L,4,"Python","1237",10) ;
	SuperInsert(L,2,"The Man","1226",10) ;
	SuperInsert(L,1,"ddd Man","1226",10) ;
	
	JudgeResponseCode(ListDelete_DuL(L,1));
	// ���ﲻ�ܵ���ɾ�����
	// ԭ���Ǵ��������L��ָ��ṹ���ָ��
	// �ӷ���������Ҫ�ı�ָ��ṹ���ָ���ָ��
	// ���ﴫ���ȥ�ı���Ǵ˺���ֵ���ݽ����ĵ�ַ
	// ����������ָ��û�з���һ��仯 
} 

void unit(){
	DuLinkList L;
	InitDuList_L(L); 
	BatchInsertInto(L);
	TraverseList(L);
//	int flag=1;
//	while(flag){
//		printf()
//	}
}

int main(){
	unit();
}
	
