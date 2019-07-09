#include<stdio.h>
#include<stdlib.h>
#define MAXQSIZE 100  // 队列可能达到的最大长度

#define OK 1
#define ERROR 0
#define OVERFLOW -1  // 状态

typedef int Status;
// - - - 队列的顺序存储结构 - - - - 
typedef int QElemType;

/*
 * 队列的存储结构 
 */
typedef struct{
	QElemType *base; // 存储空间的基地址       
	int front; // 头指针
	int rear;  // 尾指针 
}SqQueue; 

/*
 * 初始化队列 
 */
Status InitQueue(SqQueue &Q){
	Q.base=(QElemType*)malloc(sizeof(QElemType)*MAXQSIZE);
	
	// Q.base=new QElemType[MAXSIZE]; 
	
	// 为队列分配一个最大容量为MAXSIZE的空间
	if(!Q.base)
		exit(OVERFLOW); // 存储分配失败
	Q.front=Q.rear=0;   // 头指针和尾指针置为0，队列为空
	return OK; 
}

/*
 * 队列长度 
 */
int QueueLength(SqQueue Q){
	// 返回Q的元素个数，即队列的长度
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE; 
}

/*
 * 入队 
 */ 
Status EnQueue(SqQueue &Q,QElemType e){
	// 插入元素e为Q的新的元素
	if((Q.rear+1)%MAXQSIZE==Q.front) // 尾指针在循环意义上加1后等于头指针，表明队满
		return ERROR;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXQSIZE; // 队尾指针加1
	return OK; 
} 

/*
 * 出队 
 */
Status DeQueue(SqQueue &Q,QElemType &e){
	// 删除Q的队头元素，用e返回其值
	if(Q.front==Q.rear)
		return ERROR; 			  // 队空
	e=Q.base[Q.front]; 			  // 保存队头元素
	Q.front=(Q.front+1)%MAXQSIZE; // 队头指针加1
	return OK;  
}

QElemType GetHead(SqQueue Q){
	// 返回Q的队头元素，不修改队头指针
	if(Q.front!=Q.rear)			// 队列非空 
		return Q.base[Q.front]; // 返回队头元素的值，队头指针不变 
}

QElemType GetTail(SqQueue Q){
	// 返回Q的队尾元素
	if(Q.front!=Q.rear)
		return Q.base[Q.rear-1]; 
}

void ShowMenu(){
	printf("---------------------------------------------------\n");
	printf("1、入队\t\t\t\t2、出队\t\t\t\t3、输出队列元素\n");
	printf("4、取队头元素\t\t\t5、取队尾元素\t\t\t6、退出\n");
}

void TraverseSqQueue(SqQueue Q){
	int front=Q.front;
	while(front!=Q.rear){
		printf("%d ",Q.base[front]);
		front=(front+1)%MAXQSIZE;
	}
	printf("\n");
}

int main(){
	SqQueue Q;
	int k,e;
	printf("初始化的结果:%d\n",InitQueue(Q));
	printf("当前队列的长度:%d\n",QueueLength(Q));
	// 循环显示菜单，完成循环队列的一系列的操作 
	do{
		ShowMenu();	
		printf("\n请选择要执行的操作序号:");
		scanf("%d",&k);
		switch(k){
			case 1: // 执行入队操作 
				printf("请输入一个入队的数字:"); 
				scanf("%d",&e);
				if(EnQueue(Q,e)==OK){
					printf("入队成功,入队的元素是%d\n",e);
				}
				break;
			case 2: // 执行出队操作 
//				printf("出队\n");
				if(DeQueue(Q,e)==OK){
					printf("出队成功，出队的元素是%d\n",e);
				} 
				break;
			case 3: // 输入队列的长度及队列中的元素 
//				printf("队列长度以及队列中的元素\n"); 
				printf("当前队里的元素是:");
				TraverseSqQueue(Q);
				printf("当前队的长度是:%d\n",QueueLength(Q));
				break;
			case 4: // 输入队头元素
				e=GetHead(Q); 
				printf("队头的元素是%d\n",e); 
				break;
			case 5: // 输入队尾元素 
				e=GetTail(Q);
				printf("队尾的元素是%d\n",e); 
				break;
		}
		printf("\n");
	}while(k<6);
} 
