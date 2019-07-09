#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXQSIZE 5  // 队列可能达到的最大长度 

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

typedef struct{
	Book *base; // 存储空间的基地址
	int front;		 // 头指针 
	int rear; 		 // 尾指针 
}SqQueue;

/*
 * 初始化 
 */ 
Status InitQueue(SqQueue &Q){
	// 构造一个空队列Q
	Q.base=(Book*)malloc(sizeof(Book)*MAXQSIZE); // 为队列 
	if(!Q.base)	
		exit(OVERFLOW);
	Q.front=Q.rear=0;
	return OK;  
}

/*
 * 求队列长度 
 */
int QueueLength(SqQueue Q){
	// 返回Q的元素个数，即队列的长度
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE; 
}

/*
 * 入队 
 */
Status EnQueue(SqQueue &Q,Book e){
	// 插入元素e为Q的新的队尾元素
	if((Q.rear+1)%MAXQSIZE==Q.front) // 尾指针在循环意义加1后等于头指针，表明队满
		return ERROR;
	Q.base[Q.rear]=e;				 // 新元素插入队尾 
	Q.rear=(Q.rear+1)%MAXQSIZE;		 // 队尾指针加1 
	return OK;
}

/*
 * 出队 
 */ 
Status DeQueue(SqQueue &Q,Book &e){
	// 删除Q的队头元素，用e返回其值
	if(Q.front==Q.rear) 
		return ERROR; 				// 队空
	e=Q.base[Q.front];				// 保存队头元素 
	Q.front=(Q.front+1)%MAXQSIZE; 	// 队头指针加1 
	return OK; 
} 

/*
 * 取循环队列的队头元素 
 */ 
Book GetHead(SqQueue Q){
	// 返回Q的队头元素，不修改队头指针
	if(Q.front!=Q.rear)				// 队列非空 
		return Q.base[Q.front]; 	// 返回队头元素的值，队头指针不变 
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

void TraverseList(SqQueue Q){
	if(Q.front==Q.rear){
		printf("队列为空");
		return;
	}
	int front=Q.front;
	while(front!=Q.rear){
		printf("%s 		%s 		%f\n",Q.base[front].name,Q.base[front].no,Q.base[front].price);
		front=(front+1)%MAXQSIZE;
	}
}

void unit(){
	SqQueue Q;
	Book e;
	JudgeResponseCode(InitQueue(Q));
	JudgeResponseCode(EnQueue(Q,BookFactory("JAVA","123",30)));
	JudgeResponseCode(EnQueue(Q,BookFactory("C","123",30)));
	JudgeResponseCode(EnQueue(Q,BookFactory("b","123",30)));
	JudgeResponseCode(EnQueue(Q,BookFactory("ass","123",30)));
	TraverseList(Q);
	JudgeResponseCode(DeQueue(Q,e));
	JudgeResponseCode(DeQueue(Q,e));
	JudgeResponseCode(DeQueue(Q,e));
	TraverseList(Q);
	printf("\n");
	JudgeResponseCode(EnQueue(Q,BookFactory("JAVA","123",30)));
	JudgeResponseCode(EnQueue(Q,BookFactory("JAVA","123",30)));
	JudgeResponseCode(EnQueue(Q,BookFactory("JAVA","123",30)));
	TraverseList(Q);
	
	Book b=GetHead(Q);
	
	printf("\n");
	printf("%s 		%s 		%f   %d",b.name,b.no,b.price,QueueLength(Q));
}

int main(){
	unit();
}
 
