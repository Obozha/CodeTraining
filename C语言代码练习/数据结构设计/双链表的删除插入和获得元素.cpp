#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;   // Status   是函数返回值类型，其值是函数结果状态代码
typedef int ElemType; // ElemType 为可定义的数据类型，此设为int类型
int length=0;

struct Book {
	char id[50]; 	  // ISBN
	char name[50];  // 书名
	double price; // 定价
};

typedef struct DuLNode {
	Book data;    			// 数据域
	struct DuLNode *prior;   // 直接前驱
	struct DuLNode *next;   // 直接后继
} DuLNode,*DuLinkList;

Status InitDuList_L(DuLinkList &L) {
	// 构造一个空得双向列表L
	L=(DuLinkList)malloc(sizeof(DuLNode));	// 生成新结点作为头节点，用头指针L指向头结点
	L->next=NULL;  // 头结点得指针域置空
	L->prior=NULL;
	return OK;
}

DuLNode *GetElemP_DuL(DuLinkList L,int i) {
	// 在带头结点的双向链表中查找第i个元素，返回结点的地址
	DuLinkList p=L->next;
	int j=1;		// 初始化，p指向第一个结点，j为计数器
	while(j<i&&p) {	// 顺链域向后扫描，直到p指向第i个元素或p为空
		p=p->next;
		j++;
	}
	if(!p||j>i)		 // 说明i<1 i必须<=0
		return NULL; // 第i个元素不存在
	return p;
}

Status ListInSert_DuL(DuLinkList &L,int i,Book e) {
	DuLinkList s,p;
	if(!(p=GetElemP_DuL(L,i))) {
		if(!(((i==1)&&(L->next))||(i==length+1))) {
			return ERROR;
		}
	}
	if((i==1)&&(L->next==NULL)) { // 在双向链表的第一个元素上插入
		s=(DuLinkList)malloc(sizeof(DuLNode)); // 生成新结点s
		s->data=e;
		s->next=NULL;
		DuLinkList p=L;
		L->next=s;
		s->prior=L;
		length++;
	} else if(i==1) { // 在双向链表的第一个元素插入
		s=(DuLinkList)malloc(sizeof(DuLNode)); // 生成新结点s
		s->data=e; // 将结点s数据置为e
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
	// 删除带头结点的双向链表L中第i位置之前插入元素e，i的合法值为i<=i<=表长
	DuLinkList p;
	if(!(p=GetElemP_DuL(L,i))) { // 在L中确定第i个元素的位置指针p 
		return ERROR;	// p为NULL时，第i个元素不存在  
	}
	if(i==1) {
		L=L->next;	// 直接把下一个结点当作头结点来当作删除第一个结点 
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
		printf("ID:%s 书名:%s 价格:%.0lf \n",p->data.id,p->data.name,p->data.price);
		p=p->next;
	}
}

void CreateDuList_L(DuLinkList &L){
	// 正位序输入n个元素的值，建立带表头结点的双向链表L，同时建立前驱指针
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
	// 这里不能调用删除语句
	// 原因是传入进来的L是指向结构体的指针
	// 从方法调用需要改变指向结构体的指针的指针
	// 这里传入进去改变的是此函数值传递进来的地址
	// 对主函数的指针没有发生一点变化 
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
	
