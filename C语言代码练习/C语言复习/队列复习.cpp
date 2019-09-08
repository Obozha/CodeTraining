#include<stdio.h>
#include<stdlib.h>
#define MAXQSIZE 100  // ���п��ܴﵽ����󳤶�

#define OK 1
#define ERROR 0
#define OVERFLOW -1  // ״̬

typedef int Status;
// - - - ���е�˳��洢�ṹ - - - - 
typedef int QElemType;

/*
 * ���еĴ洢�ṹ 
 */
typedef struct{
	QElemType *base; // �洢�ռ�Ļ���ַ       
	int front; // ͷָ��
	int rear;  // βָ�� 
}SqQueue; 

/*
 * ��ʼ������ 
 */
Status InitQueue(SqQueue &Q){
	Q.base=(QElemType*)malloc(sizeof(QElemType)*MAXQSIZE);
	
	// Q.base=new QElemType[MAXSIZE]; 
	
	// Ϊ���з���һ���������ΪMAXSIZE�Ŀռ�
	if(!Q.base)
		exit(OVERFLOW); // �洢����ʧ��
	Q.front=Q.rear=0;   // ͷָ���βָ����Ϊ0������Ϊ��
	return OK; 
}

/*
 * ���г��� 
 */
int QueueLength(SqQueue Q){
	// ����Q��Ԫ�ظ����������еĳ���
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE; 
}

/*
 * ��� 
 */ 
Status EnQueue(SqQueue &Q,QElemType e){
	// ����Ԫ��eΪQ���µ�Ԫ��
	if((Q.rear+1)%MAXQSIZE==Q.front) // βָ����ѭ�������ϼ�1�����ͷָ�룬��������
		return ERROR;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXQSIZE; // ��βָ���1
	return OK; 
} 

/*
 * ���� 
 */
Status DeQueue(SqQueue &Q,QElemType &e){
	// ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
	if(Q.front==Q.rear)
		return ERROR; 			  // �ӿ�
	e=Q.base[Q.front]; 			  // �����ͷԪ��
	Q.front=(Q.front+1)%MAXQSIZE; // ��ͷָ���1
	return OK;  
}

QElemType GetHead(SqQueue Q){
	// ����Q�Ķ�ͷԪ�أ����޸Ķ�ͷָ��
	if(Q.front!=Q.rear)			// ���зǿ� 
		return Q.base[Q.front]; // ���ض�ͷԪ�ص�ֵ����ͷָ�벻�� 
}

QElemType GetTail(SqQueue Q){
	// ����Q�Ķ�βԪ��
	if(Q.front!=Q.rear)
		return Q.base[Q.rear-1]; 
}

void ShowMenu(){
	printf("---------------------------------------------------\n");
	printf("1�����\t\t\t\t2������\t\t\t\t3���������Ԫ��\n");
	printf("4��ȡ��ͷԪ��\t\t\t5��ȡ��βԪ��\t\t\t6���˳�\n");
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
	printf("��ʼ���Ľ��:%d\n",InitQueue(Q));
	printf("��ǰ���еĳ���:%d\n",QueueLength(Q));
	// ѭ����ʾ�˵������ѭ�����е�һϵ�еĲ��� 
	do{
		ShowMenu();	
		printf("\n��ѡ��Ҫִ�еĲ������:");
		scanf("%d",&k);
		switch(k){
			case 1: // ִ����Ӳ��� 
				printf("������һ����ӵ�����:"); 
				scanf("%d",&e);
				if(EnQueue(Q,e)==OK){
					printf("��ӳɹ�,��ӵ�Ԫ����%d\n",e);
				}
				break;
			case 2: // ִ�г��Ӳ��� 
//				printf("����\n");
				if(DeQueue(Q,e)==OK){
					printf("���ӳɹ������ӵ�Ԫ����%d\n",e);
				} 
				break;
			case 3: // ������еĳ��ȼ������е�Ԫ�� 
//				printf("���г����Լ������е�Ԫ��\n"); 
				printf("��ǰ�����Ԫ����:");
				TraverseSqQueue(Q);
				printf("��ǰ�ӵĳ�����:%d\n",QueueLength(Q));
				break;
			case 4: // �����ͷԪ��
				e=GetHead(Q); 
				printf("��ͷ��Ԫ����%d\n",e); 
				break;
			case 5: // �����βԪ�� 
				e=GetTail(Q);
				printf("��β��Ԫ����%d\n",e); 
				break;
		}
		printf("\n");
	}while(k<6);
} 
