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

// - - - - 链栈的存储结构 - - - -
typedef struct StackNode{
	Book data;
	struct StackNode *next;
}StackNode,*LinkStack; 

/*
 * 初始化
 * 链表的初始化操作就是构造一个空栈，因为没必要设头结点
 * 所以直接将栈顶置空即可  
 */
Status InitStack(LinkStack &S){
	// 构造一个空栈S，栈顶指针置空
	S=NULL;
	return OK; 
}

/*
 * 入栈 
 */
Status Push(LinkStack &S,Book e){
	// 在栈顶插入元素e
	StackNode *p=(LinkStack)malloc(sizeof(StackNode));	// 生成新结点 
	p->data=e;											// 将新结点域置为e 
	p->next=S;											// 将新结点插入栈顶 
	S=p;												// 修改栈顶指针为p 
	return OK;
}

Status SuperPush(LinkStack &S,const char*name,const char*no,float price){
	Push(S,BookFactory(name,no,price));
}

/*
 * 出栈 
 */ 
Status Pop(LinkStack &S,Book &e){
	// 删除S的栈顶元素，用e返回其值
	if(S==NULL)
		return ERROR; // 栈空
	e=S->data;		  // 将栈顶元素赋给e
	StackNode* p=S;	  // 用p临时保存栈顶元素空间，以备释放
	S=S->next;
	free(p);		  // 释放原栈顶元素的空间 
	return OK;
}

Book GetTop(LinkStack S){
	// 返回S的栈顶元素，不修改栈顶指针
	if(S!=NULL)	// 栈非空
		return S->data;	// 返回栈顶元素的值，栈顶指针不变 
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
		printf("数据项为空");
	}
	printf("===============================================\n");
}

void unit(){
	LinkStack S;
	InitStack(S); // 初始化
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
 
