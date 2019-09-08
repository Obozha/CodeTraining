#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;
typedef struct{
	char no[50]; 
	char name[50];
	float price;
}Book;

Book BookFactory(const char*name,const char*no,float price){
	Book e;
	strcpy(e.name,name);
	strcpy(e.no,no);
	e.price=price;
	return e;
}

// - - - - ��ջ�Ĵ洢�ṹ - - - -
typedef struct StackNode{
	Book data;
	struct StackNode *next;
}StackNode,*LinkStack; 

/*
 * ��ʼ��
 * ����ĳ�ʼ���������ǹ���һ����ջ����Ϊû��Ҫ��ͷ���
 * ����ֱ�ӽ�ջ���ÿռ���  
 */
Status InitStack(LinkStack &S){
	// ����һ����ջS��ջ��ָ���ÿ�
	S=NULL;
	return OK; 
}

/*
 * ��ջ 
 */
Status Push(LinkStack &S,Book e){
	// ��ջ������Ԫ��e
	StackNode *p=(LinkStack)malloc(sizeof(StackNode));	// �����½�� 
	p->data=e;											// ���½������Ϊe 
	p->next=S;											// ���½�����ջ�� 
	S=p;												// �޸�ջ��ָ��Ϊp 
	return OK;
}

Status SuperPush(LinkStack &S,const char*name,const char*no,float price){
	Push(S,BookFactory(name,no,price));
}

/*
 * ��ջ 
 */ 
Status Pop(LinkStack &S,Book &e){
	// ɾ��S��ջ��Ԫ�أ���e������ֵ
	if(S==NULL)
		return ERROR; // ջ��
	e=S->data;		  // ��ջ��Ԫ�ظ���e
	StackNode* p=S;	  // ��p��ʱ����ջ��Ԫ�ؿռ䣬�Ա��ͷ�
	S=S->next;
	free(p);		  // �ͷ�ԭջ��Ԫ�صĿռ� 
	return OK;
}

Book GetTop(LinkStack S){
	// ����S��ջ��Ԫ�أ����޸�ջ��ָ��
	if(S!=NULL)	// ջ�ǿ�
		return S->data;	// ����ջ��Ԫ�ص�ֵ��ջ��ָ�벻�� 
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

void PrintStackNode(StackNode *p){
	printf("%-10s%-10s%-10.0f\n",p->data.name,p->data.no,p->data.price);
}

void TraverseList(LinkStack S){
	printf("===============================================\n");
	LinkStack p=S;
	if(p){
		while(p){
			PrintStackNode(p); 
			p=p->next;
		}
	}else{
		printf("������Ϊ��");
	}
	printf("===============================================\n");
}

void unit(){
	LinkStack S;
	InitStack(S); // ��ʼ��
	SuperPush(S,"JAVA","123312",30);
	SuperPush(S,"C","123313",32);
	SuperPush(S,"PYTHON","123314",33);
	SuperPush(S,"LOGIN","123315",34);
	SuperPush(S,"JACK","123316",35);
	TraverseList(S);
	
	Book e;
	Pop(S,e);
	printf("%s %s %.0f\n",e.name,e.no,e.price);
	TraverseList(S);
	
	Book c=GetTop(S);
	printf("%s %s %.0f\n",c.name,c.no,c.price);
}

int main(){
	unit();
} 
 
