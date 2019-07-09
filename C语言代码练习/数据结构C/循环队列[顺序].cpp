#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXQSIZE 5  // ���п��ܴﵽ����󳤶� 

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
	Book *base; // �洢�ռ�Ļ���ַ
	int front;		 // ͷָ�� 
	int rear; 		 // βָ�� 
}SqQueue;

/*
 * ��ʼ�� 
 */ 
Status InitQueue(SqQueue &Q){
	// ����һ���ն���Q
	Q.base=(Book*)malloc(sizeof(Book)*MAXQSIZE); // Ϊ���� 
	if(!Q.base)	
		exit(OVERFLOW);
	Q.front=Q.rear=0;
	return OK;  
}

/*
 * ����г��� 
 */
int QueueLength(SqQueue Q){
	// ����Q��Ԫ�ظ����������еĳ���
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE; 
}

/*
 * ��� 
 */
Status EnQueue(SqQueue &Q,Book e){
	// ����Ԫ��eΪQ���µĶ�βԪ��
	if((Q.rear+1)%MAXQSIZE==Q.front) // βָ����ѭ�������1�����ͷָ�룬��������
		return ERROR;
	Q.base[Q.rear]=e;				 // ��Ԫ�ز����β 
	Q.rear=(Q.rear+1)%MAXQSIZE;		 // ��βָ���1 
	return OK;
}

/*
 * ���� 
 */ 
Status DeQueue(SqQueue &Q,Book &e){
	// ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
	if(Q.front==Q.rear) 
		return ERROR; 				// �ӿ�
	e=Q.base[Q.front];				// �����ͷԪ�� 
	Q.front=(Q.front+1)%MAXQSIZE; 	// ��ͷָ���1 
	return OK; 
} 

/*
 * ȡѭ�����еĶ�ͷԪ�� 
 */ 
Book GetHead(SqQueue Q){
	// ����Q�Ķ�ͷԪ�أ����޸Ķ�ͷָ��
	if(Q.front!=Q.rear)				// ���зǿ� 
		return Q.base[Q.front]; 	// ���ض�ͷԪ�ص�ֵ����ͷָ�벻�� 
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
		printf("����Ϊ��");
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
 
