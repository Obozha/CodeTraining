#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;
typedef struct{
	char name[50];
	char no[50];
	float price;
}Book;

Book BookFactory(const char*name,const char*no,float price){
	Book e;
	strcpy(e.name,name);
	strcpy(e.no,no);
	e.price=price;
	return e;
}

//- - - - - 队列的链式存储结构 - - - - 
typedef struct QNode{
	Book data;
	struct QNode *next;	
}QNode,*QueuePtr;


typedef struct {
	QueuePtr front;		// 队头指针 
	QueuePtr rear;		// 队尾指针 
}LinkQueue;

/*
 * 链队的初始化
 * 算法步骤
 * ①生成新结点作为头结点，队头和队尾指针指向此结点
 * ②头结点的指针域置空 
 */ 
Status InitQueue(LinkQueue &Q){
	// 构造一个空队列Q
	Q.front=Q.rear= (QueuePtr)malloc(sizeof(QNode)); // 生成新结点作为头结点，队头和队尾指针指向此结点
	Q.front->next=NULL; // 头结点的指针域置空 
	return OK; 
}

/*
 * 链队的入队
 * ①为入队元素分配结点空间，用指针p指向。
 * ②将新结点数据置为e
 * ③将新结点插入到队尾
 * ④修改队尾指针为p 
 */ 
Status EnQueue(LinkQueue &Q,Book e){
	// 插入元素为e为Q的新的队尾元素
	QueuePtr p=QueuePtr(malloc(sizeof(QNode))); // 为入队元素分配结点空间，用指针p指向 
	p->data=e; 									// 将新结点数据置为e
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK; 
}

/*
 * 链队的出队
 * ①判断队列是否为空，若空则返回ERROR。
 * ②临时保存队头元素的空间，以备释放。
 * ③修改头结点的指针域，指向下一个结点。
 * ④判断出队元素是否为最后一个元素，若是，则将队尾指针重新赋值，指向头结点。
 * ⑤释放原队头元素的空间 
 */
Status DeQueue(LinkQueue &Q,Book &e){
	if(Q.front==Q.rear)			// 若队列空，则返回ERROR 
		return ERROR;			
	QueuePtr p=Q.front->next;	// p指向队头元素 
	e=p->data;					// e保存队头元素的值 
	Q.front->next=p->next;		// 修改头结点的指针域 
	if(Q.rear==p) 				// 最后一个元素被删，队尾指针指向头结点。 
		Q.rear=Q.front;
	free(p);
	return OK;
}

/*
 * 取循环队列的队头元素 
 */
Book GetHead(LinkQueue Q){
	// 返回Q的队头元素，不修改队头指针
	if(Q.front!=Q.rear)					// 队列非空 
		return Q.front->next->data; 	// 返回队头元素的值，队头指针不变 
}

/*
 * 遍历队列 
 */ 
void TraverseList(LinkQueue Q){
	QueuePtr p=Q.front->next;
	while(p){
		printf("%s		%s		%.0f\n",p->data.name,p->data.no,p->data.price);
		p=p->next;
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

void unit(){
	LinkQueue Q;
	Book e;
	
	JudgeResponseCode(InitQueue(Q));
	JudgeResponseCode(EnQueue(Q,BookFactory("JAVA","123",30)));
	JudgeResponseCode(EnQueue(Q,BookFactory("C","456",30)));
	JudgeResponseCode(EnQueue(Q,BookFactory("A","789",30)));
	JudgeResponseCode(EnQueue(Q,BookFactory("B","333",30)));
	TraverseList(Q);
//	DeQueue(Q,e);
//	DeQueue(Q,e);
//	DeQueue(Q,e);
//	DeQueue(Q,e);
	printf("\n");
	e=GetHead(Q);
	printf("%s",e.name);
//	TraverseList(Q);
} 

int main(){
	unit();
}
