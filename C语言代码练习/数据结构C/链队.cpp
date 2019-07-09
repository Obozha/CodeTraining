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

//- - - - - ���е���ʽ�洢�ṹ - - - - 
typedef struct QNode{
	Book data;
	struct QNode *next;	
}QNode,*QueuePtr;


typedef struct {
	QueuePtr front;		// ��ͷָ�� 
	QueuePtr rear;		// ��βָ�� 
}LinkQueue;

/*
 * ���ӵĳ�ʼ��
 * �㷨����
 * �������½����Ϊͷ��㣬��ͷ�Ͷ�βָ��ָ��˽��
 * ��ͷ����ָ�����ÿ� 
 */ 
Status InitQueue(LinkQueue &Q){
	// ����һ���ն���Q
	Q.front=Q.rear= (QueuePtr)malloc(sizeof(QNode)); // �����½����Ϊͷ��㣬��ͷ�Ͷ�βָ��ָ��˽��
	Q.front->next=NULL; // ͷ����ָ�����ÿ� 
	return OK; 
}

/*
 * ���ӵ����
 * ��Ϊ���Ԫ�ط�����ռ䣬��ָ��pָ��
 * �ڽ��½��������Ϊe
 * �۽��½����뵽��β
 * ���޸Ķ�βָ��Ϊp 
 */ 
Status EnQueue(LinkQueue &Q,Book e){
	// ����Ԫ��ΪeΪQ���µĶ�βԪ��
	QueuePtr p=QueuePtr(malloc(sizeof(QNode))); // Ϊ���Ԫ�ط�����ռ䣬��ָ��pָ�� 
	p->data=e; 									// ���½��������Ϊe
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK; 
}

/*
 * ���ӵĳ���
 * ���ж϶����Ƿ�Ϊ�գ������򷵻�ERROR��
 * ����ʱ�����ͷԪ�صĿռ䣬�Ա��ͷš�
 * ���޸�ͷ����ָ����ָ����һ����㡣
 * ���жϳ���Ԫ���Ƿ�Ϊ���һ��Ԫ�أ����ǣ��򽫶�βָ�����¸�ֵ��ָ��ͷ��㡣
 * ���ͷ�ԭ��ͷԪ�صĿռ� 
 */
Status DeQueue(LinkQueue &Q,Book &e){
	if(Q.front==Q.rear)			// �����пգ��򷵻�ERROR 
		return ERROR;			
	QueuePtr p=Q.front->next;	// pָ���ͷԪ�� 
	e=p->data;					// e�����ͷԪ�ص�ֵ 
	Q.front->next=p->next;		// �޸�ͷ����ָ���� 
	if(Q.rear==p) 				// ���һ��Ԫ�ر�ɾ����βָ��ָ��ͷ��㡣 
		Q.rear=Q.front;
	free(p);
	return OK;
}

/*
 * ȡѭ�����еĶ�ͷԪ�� 
 */
Book GetHead(LinkQueue Q){
	// ����Q�Ķ�ͷԪ�أ����޸Ķ�ͷָ��
	if(Q.front!=Q.rear)					// ���зǿ� 
		return Q.front->next->data; 	// ���ض�ͷԪ�ص�ֵ����ͷָ�벻�� 
}

/*
 * �������� 
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
