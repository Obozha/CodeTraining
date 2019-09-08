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
	Book data; // 数据域
	struct LNode *next; // 指针域
}LNode,*LinkList;
// *LinkList为Lnode类型的指针 

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
 * 单链表初始化头节点 
*/ 
Status InitList(LNode **L){
	*L=(LNode*)malloc(sizeof(LNode));
	if(*L==NULL){
		printf("申请空间失败");
	}
	if(InitHeadNode(*L)==OK){
		printf("已初始化头节点...\n");
		printf("%s\n",(*L)->data.name);
		printf("%s\n",(*L)->data.no);
		printf("%f\n",(*L)->data.price);
	}
	(*L)->next=NULL;
	return OK;
}

/*  
 * 单链表初始化头节点 
*/ 
Status InitHeadNode(LNode *L){
	Book BaseBookifm; 
	strcpy(BaseBookifm.name,"书名");
	strcpy(BaseBookifm.no,"ISBN");
	BaseBookifm.price=0;
	L->data=BaseBookifm;
	// L->data=BaseBookifm
	// 这里是直接赋值 
	return OK;
}

/*  
 * 单链表返回长度 
*/ 
int ListLength(LinkList L){
	// 返回L中元素个数
	LinkList p;
	p=L->next; // p指向第一个结点
	int i=0;
	while(p){ // 遍历单链表，统计结点数 
		i++;
		p=p->next;
	}
	return i;
}

/*  
 * 单链表是否为空 
*/ 
int ListEmpty(LNode *L){
	// 若L为空表，  否则返回0
	if(L->next){ // 非空 
		return 0;
	} else{
		return 1;
	}
}

/*  
 * 单链表是否为空 
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
 
Status GetElem(LinkList L,int i,Book *e){
	LinkList p=L->next; // 跳过头节点 
	int j=1;
	while(p&&j<i){ // 向后扫描，直到p指向第i个元素 或p为空 
		p=p->next;
		++j;
	} 
	if(!p||j>i)
		return ERROR;
	*e=p->data; // 取第i个元素
	return OK; 
} // GetElem

Status ListInsert(LNode *L,int i,Book e){
	LNode *p=L;
	int j=0;
	while(p&&j<i-1){
		p=p->next;
		j++;  // 寻找i-1个结点 
	}
	if(!p||j>i-1){
		return ERROR; //i大于表长+1或者小于1 
	}
	LNode *Node=(LNode*)malloc(sizeof(LNode)); 
	//首先LNode是局部变量，在栈里，函数消亡的时候LNode也跟着消亡
	// 所以不能LNode Node声明在函数里，然后让插入单链表中
	
	// 使用malloc是在堆中申请长度为 LNode的连续空间
	// 进而申请到一个结点
	// 这个结点系统不会自动回收，需要程序员自己进行释放
	// 这样就可以保证结点不会被消亡
	// 同时即将消亡的Node指针，因为及时的链接到了上一个节点指针上
	// 因此得到了保留 
	 
	Node->data=e;
	Node->next=p->next;
	p->next=Node;

// ==================================== 
//  以下为错误代码 
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
	// 在带头结点的单链表，删除第i个元素
	LNode *p=L;
	int j=0;
	while((p->next)&&(j<i-1)){  // 查找第i-1个结点，p指向该结点
		p=p->next;
		j++; 
	} 
	if(!(p->next)||(j>i-1)){	// 当i>n或i<1时，删除位置不合理 
		return ERROR;
	}
	LNode* q=p->next;
	p->next=q->next;
	free(q);
	return OK; 
}

void CreateList_F(LinkList *L,int n){
	*L=(LNode*)malloc(sizeof(LNode));
	(*L)->next=NULL; // 先建立一个带头结点的单链表
	
	InitHeadNode(*L); // 头节点初始化 
	
	int i;
	for(i=n;i>0;i--){
		LNode *p=(LNode*)malloc(sizeof(LNode));
		char name[50];
		char no[20];
		// 要输入字符串使用字符数组，而不能使用字符指针  
		
		float price;
		printf("请输入书名，ISBN号，价格： ");
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
	// 正位序输入n个元素的值，建立带头结点的单链表L
	*L=(LNode*)malloc(sizeof(LNode));
	(*L)->next=NULL;
	InitHeadNode(*L);
	LNode *r=*L;  // 尾指针r指向头节点 
	int i;
	for(i=0;i<n;i++){
		LNode *l=(LNode*)malloc(sizeof(LNode)); // 生成新结点 
		char name[50];
		char no[20];
		float price;
		printf("请输入书名，ISBN，价格：");
		scanf("%s %s %f",name,no,&price);
		Book book;
		strcpy(book.name,name);
		strcpy(book.no,no);
		printf("%s",book.name);
		book.price=price;
		// 输入元素值 
		printf("Log"); 
		l->data=book;  
		l->next=NULL;
		r->next=l; // 插入到表尾部 
		r=l; //r指向新的尾结点 
	}
}

void AccessNodesData(LNode* L){
	LNode* p=L;
	printf("头节点信息为：\n");
	printf("%-15s|	%-15s|	%-2.0f|\n",p->data.name,p->data.no,p->data.price);
	p=p->next; // 跑出头节点 
	do{
		printf("%-15s|	%-15s|	%-2.0f|\n",p->data.name,p->data.no,p->data.price);
		p=p->next;
	}while(p!=NULL); // !! 注意是p!=NULL 而不是p->next!=NULL 
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
	printf("==================================初始化数据=====================================\n"); 
	JudgeResponseCode(SuperListInsert(p,1,"JAVA","2019",38));
	JudgeResponseCode(SuperListInsert(p,2,"ASP.NET","2020",39));
	JudgeResponseCode(SuperListInsert(p,3,"数据结构","2021",40));
	JudgeResponseCode(SuperListInsert(p,4,"路由与交换","2022",41));
	JudgeResponseCode(SuperListInsert(p,5,"Linux","2023",42));
	JudgeResponseCode(SuperListInsert(p,6,"数据库系统概论","2024",43));
	JudgeResponseCode(SuperListInsert(p,7,"C语言程序设计","2025",44));
	JudgeResponseCode(SuperListInsert(p,8,"网络安全","2026",45));
	printf("当前一共有%d个数据\n",ListLength(p));
	printf("==================================初始化数据=====================================\n\n");
}

void Unit(){
//	LNode l;	  // LNode结构体 
	LNode *p;  // p为指向LNode的指针体 
	LNode **q=&p; // q指向指针的指针 
	
	/* 初始化指针需要给入 指向指针的指针，通过指向指针的指针来改变指针的地址
	 * 这里是通过二级指针传递 
	 */
	InitList(q);  
	 
	/*
	 * 批量插入数据 
	 */ 
	BatchInsert(p);
	AccessNodesData(p);
	
	/*
	 * 测试获得元素 
	 */ 
	Book *b;
	GetElem(p,3,b);
	printf("GetElem获取的数据为:%s %s %.0f\n",b->name,b->no,b->price); 
	
	/*
	 * 删除元素 
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
//	// 返回L中值为e的数据元素的地址，查找返回NULL
//	LinkList p=L;
//	p=L->next;
//	while(p&&p->data!=e){
//		p=p->next;
//	} 
//	return p;
//}

//int LocateElemNum(LinkList L,Book e){
//	// 返回L中值为e的数据元素的位置序号，查找失败返回0
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

// 测试局部变量的生命周期 
//Book *hello(){
//	Book b;
//	b.price=20;
//	strcpy(b.name,"HelloWorld");
//	strcpy(b.no,"SSINK");
//	Book *p=&b;
//	return p;
//}
