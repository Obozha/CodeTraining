#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 200

typedef int Status;
typedef struct{
	char no[20];
	char name[50];
	float price;
}Book;

typedef struct LNode{
	Book data; // ������
	struct LNode *next; // ָ����
}LNode,*LinkList;
// *LinkListΪLnode���͵�ָ�� 

Status ClearList(LinkList L);
Status DestoryList(LinkList L);
Status GetElem(LinkList L,int i,Book *e);
Status InitList(LNode **L);
Status InitHeadNode(LNode *L);
Status ListInsert(LNode *L,int i,Book e);
Status SuperListInsert(LNode *L,const char* name,const char* no,float price);

int ListLength(LinkList L);
int ListEmpty(LinkList L);

void AccessNodesData(LNode* L);
void BatchInsert(LNode *p);
void CreateList_F(LinkList *L,int n);
void JudgeResponseCode(Status ResponseCode);
void Unit();

/*  
 * �������ʼ��ͷ�ڵ� 
*/ 
Status InitList(LNode **L){
	*L=(LNode*)malloc(sizeof(LNode));
	if(*L==NULL){
		printf("����ռ�ʧ��");
	}
	if(InitHeadNode(*L)==OK){
		printf("�ѳ�ʼ��ͷ�ڵ�...\n");
		printf("%s\n",(*L)->data.name);
		printf("%s\n",(*L)->data.no);
		printf("%f\n",(*L)->data.price);
	}
	(*L)->next=NULL;
	return OK;
}

/*  
 * �������ʼ��ͷ�ڵ� 
*/ 
Status InitHeadNode(LNode *L){
	Book BaseBookifm; 
	strcpy(BaseBookifm.name,"����");
	strcpy(BaseBookifm.no,"ISBN");
	BaseBookifm.price=0;
	L->data=BaseBookifm;
	// L->data=BaseBookifm
	// ������ֱ�Ӹ�ֵ 
	return OK;
}

/*  
 * �������س��� 
*/ 
int ListLength(LinkList L){
	// ����L��Ԫ�ظ���
	LinkList p;
	p=L->next; // pָ���һ�����
	int i=0;
	while(p){ // ����������ͳ�ƽ���� 
		i++;
		p=p->next;
	}
	return i;
}

/*  
 * �������Ƿ�Ϊ�� 
*/ 
int ListEmpty(LNode *L){
	// ��LΪ�ձ�  ���򷵻�0
	if(L->next){ // �ǿ� 
		return 0;
	} else{
		return 1;
	}
}

/*  
 * �������Ƿ�Ϊ�� 
*/ 
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
 
Status GetElem(LinkList L,int i,Book *e){
	LinkList p=L->next; // ����ͷ�ڵ� 
	int j=1;
	while(p&&j<i){ // ���ɨ�裬ֱ��pָ���i��Ԫ�� ��pΪ�� 
		p=p->next;
		++j;
	} 
	if(!p||j>i)
		return ERROR;
	*e=p->data; // ȡ��i��Ԫ��
	return OK; 
} // GetElem

Status ListInsert(LNode *L,int i,Book e){
	LNode *p=L;
	int j=0;
	while(p&&j<i-1){
		p=p->next;
		j++;  // Ѱ��i-1����� 
	}
	if(!p||j>i-1){
		return ERROR; //i���ڱ�+1����С��1 
	}
	LNode *Node=(LNode*)malloc(sizeof(LNode)); 
	//����LNode�Ǿֲ���������ջ�����������ʱ��LNodeҲ��������
	// ���Բ���LNode Node�����ں����Ȼ���ò��뵥������
	
	// ʹ��malloc���ڶ������볤��Ϊ LNode�������ռ�
	// �������뵽һ�����
	// ������ϵͳ�����Զ����գ���Ҫ����Ա�Լ������ͷ�
	// �����Ϳ��Ա�֤��㲻�ᱻ����
	// ͬʱ����������Nodeָ�룬��Ϊ��ʱ�����ӵ�����һ���ڵ�ָ����
	// ��˵õ��˱��� 
	 
	Node->data=e;
	Node->next=p->next;
	p->next=Node;

// ==================================== 
//  ����Ϊ������� 
//	LNode N;
//	LNode *q=&N;
//	q->data=e;
//	q->next=p->next;
//	p->next=q;
//	printf("%s",p->next->data.name);
//	printf("%s",p->next->data.no);
//	printf("%f",p->next->data.price);
// ==================================== 
	return OK;
}

Status SuperListInsert(LNode *L,int i,const char* name,const char* no,float price){
	Book book;
	strcpy(book.name,name);
	strcpy(book.no,no);
	book.price=price;
	if(ListInsert(L,i,book)==OK){
		return OK;
	}
} 

Status ListDelete(LinkList L,int i){
	// �ڴ�ͷ���ĵ�����ɾ����i��Ԫ��
	LNode *p=L;
	int j=0;
	while((p->next)&&(j<i-1)){  // ���ҵ�i-1����㣬pָ��ý��
		p=p->next;
		j++; 
	} 
	if(!(p->next)||(j>i-1)){	// ��i>n��i<1ʱ��ɾ��λ�ò����� 
		return ERROR;
	}
	LNode* q=p->next;
	p->next=q->next;
	free(q);
	return OK; 
}

void CreateList_F(LinkList *L,int n){
	*L=(LNode*)malloc(sizeof(LNode));
	(*L)->next=NULL; // �Ƚ���һ����ͷ���ĵ�����
	
	InitHeadNode(*L); // ͷ�ڵ��ʼ�� 
	
	int i;
	for(i=n;i>0;i--){
		LNode *p=(LNode*)malloc(sizeof(LNode));
		char name[50];
		char no[20];
		// Ҫ�����ַ���ʹ���ַ����飬������ʹ���ַ�ָ��  
		
		float price;
		printf("������������ISBN�ţ��۸� ");
		scanf("%s %s %f",name,no,&price);
		printf("Log");
		Book book;
		strcpy(book.name,name);
		strcpy(book.no,no);
		book.price=price;
		
		p->data=book;
		p->next=(*L)->next;
		(*L)->next=p;
	} 
} // CreateList_F

void CreateList_L(LinkList *L,int n){
	// ��λ������n��Ԫ�ص�ֵ��������ͷ���ĵ�����L
	*L=(LNode*)malloc(sizeof(LNode));
	(*L)->next=NULL;
	InitHeadNode(*L);
	LNode *r=*L;  // βָ��rָ��ͷ�ڵ� 
	int i;
	for(i=0;i<n;i++){
		LNode *l=(LNode*)malloc(sizeof(LNode)); // �����½�� 
		char name[50];
		char no[20];
		float price;
		printf("������������ISBN���۸�");
		scanf("%s %s %f",name,no,&price);
		Book book;
		strcpy(book.name,name);
		strcpy(book.no,no);
		printf("%s",book.name);
		book.price=price;
		// ����Ԫ��ֵ 
		printf("Log"); 
		l->data=book;  
		l->next=NULL;
		r->next=l; // ���뵽��β�� 
		r=l; //rָ���µ�β��� 
	}
}

void AccessNodesData(LNode* L){
	LNode* p=L;
	printf("ͷ�ڵ���ϢΪ��\n");
	printf("%-15s|	%-15s|	%-2.0f|\n",p->data.name,p->data.no,p->data.price);
	p=p->next; // �ܳ�ͷ�ڵ� 
	do{
		printf("%-15s|	%-15s|	%-2.0f|\n",p->data.name,p->data.no,p->data.price);
		p=p->next;
	}while(p!=NULL); // !! ע����p!=NULL ������p->next!=NULL 
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

void BatchInsert(LNode *p){
	printf("==================================��ʼ������=====================================\n"); 
	JudgeResponseCode(SuperListInsert(p,1,"JAVA","2019",38));
	JudgeResponseCode(SuperListInsert(p,2,"ASP.NET","2020",39));
	JudgeResponseCode(SuperListInsert(p,3,"���ݽṹ","2021",40));
	JudgeResponseCode(SuperListInsert(p,4,"·���뽻��","2022",41));
	JudgeResponseCode(SuperListInsert(p,5,"Linux","2023",42));
	JudgeResponseCode(SuperListInsert(p,6,"���ݿ�ϵͳ����","2024",43));
	JudgeResponseCode(SuperListInsert(p,7,"C���Գ������","2025",44));
	JudgeResponseCode(SuperListInsert(p,8,"���簲ȫ","2026",45));
	printf("��ǰһ����%d������\n",ListLength(p));
	printf("==================================��ʼ������=====================================\n\n");
}

void Unit(){
//	LNode l;	  // LNode�ṹ�� 
	LNode *p;  // pΪָ��LNode��ָ���� 
	LNode **q=&p; // qָ��ָ���ָ�� 
	
	/* ��ʼ��ָ����Ҫ���� ָ��ָ���ָ�룬ͨ��ָ��ָ���ָ�����ı�ָ��ĵ�ַ
	 * ������ͨ������ָ�봫�� 
	 */
	InitList(q);  
	 
	/*
	 * ������������ 
	 */ 
	BatchInsert(p);
	AccessNodesData(p);
	
	/*
	 * ���Ի��Ԫ�� 
	 */ 
	Book *b;
	GetElem(p,3,b);
	printf("GetElem��ȡ������Ϊ:%s %s %.0f\n",b->name,b->no,b->price); 
	
	/*
	 * ɾ��Ԫ�� 
	 */ 
	 JudgeResponseCode(ListDelete(p,8));
	 AccessNodesData(p);
}

void Unit_v2(){
	printf("Unit_V2\n");
	LNode q;
	LNode *p=&q; 
	LNode **L=&p;
	CreateList_L(L,3);
//	CreateList_F(L,3);
	
	AccessNodesData(*L);
}

int main(){
	Unit_v2();
}




//LNode *LocateElem(LinkList L,Book e){
//	// ����L��ֵΪe������Ԫ�صĵ�ַ�����ҷ���NULL
//	LinkList p=L;
//	p=L->next;
//	while(p&&p->data!=e){
//		p=p->next;
//	} 
//	return p;
//}

//int LocateElemNum(LinkList L,Book e){
//	// ����L��ֵΪe������Ԫ�ص�λ����ţ�����ʧ�ܷ���0
//	LinkList p=L->next;
//	int j=1;
//	while(p&&p->data!=e){
//		p=p->next;
//		j++; 
//	}
//	if(p)
//		return j;
//	else 
//		return 0;
//}

// ���Ծֲ��������������� 
//Book *hello(){
//	Book b;
//	b.price=20;
//	strcpy(b.name,"HelloWorld");
//	strcpy(b.no,"SSINK");
//	Book *p=&b;
//	return p;
//}
