#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Status;
typedef int ElemType;
// 单链表的存储结构 
typedef struct LNode{
	ElemType data;	    // 结点的数据域
	struct LNode *next; // 结点的指针域  
}LNode,*LinkList;

int La_data[]={3,5,8,11};
int Lb_data[]={2,6,8,9,11,15,20};

Status InitList(LinkList &L){
	// 构造一个空的单链表L
	L=(LinkList)malloc(sizeof(LNode)); 
	L->next=NULL;
	return OK;
} 

Status GetElem(LinkList L,int i,ElemType &e){
	LinkList p=L->next;
	int j=1; // 初始化，p指向首元结点，计数器j初赋值为1
	while(p&&j<i){
		p=p->next; // p就指向下一个结点
		j++;	   // 计数器j相应加1 
	}
	if(!p||j>i) // i值不合法i>表长n或i<=0 
		return ERROR;
	e=p->data;
	return OK; 
}

LNode *LocateElem(LinkList L,ElemType e){
	// 在带头结点的单链表L中查找值为e的元素
	LinkList p=L->next; // 初始化，p指向首元结点
	while(p&&p->data!=e)
		p=p->next;
	return p; 
}

Status ListInsert(LinkList &L,int i,ElemType e){
	// 在带头结点的单链表L中第i个位置插入值为e的新结点
	LinkList p=L;
	int j=0;
	while(p&&(j<i-1)) {
		p=p->next;
		j++;
	}
	if(!p||j>i-1)
		return ERROR;  // i>n+1或者i<1
	LinkList s=(LinkList)malloc(sizeof(LNode));
	s->data=e;		 // 将结点*s的数据域置为e 
	s->next=p->next; // 将结点*s的指针域指向结点ai
	p->next=s;
	return OK;
}

Status ListDelete(LinkList &L,int i){
	// 在带头结点的单链表中，删除第i个元素
	LinkList p=L;
	int j=0;
	while((p->next)&&(j<i-1)){ // 查找第i-1个结点，p指向改 
		p=p->next;
		j++;
	}
	if(p->next||j>i-1)
		return ERROR;
	LinkList q=p->next;
	p->next=q->next;
	free(q);
	return OK;
}

void MergeList_L(LinkList &LA,LinkList &LB,LinkList &LC){
	// 已知单链表LA和LB的元素按值非递减排列
	LinkList pa=LA->next,pb=LB->next;
	LC=LA;
	LNode* pc=LC;
	while(pa&&pb){
		// LA和LB均未到达表尾，依次“摘取”两表中值最小的结点插入LC的最后
		if(pa->data<=pb->data){ //“摘取”pa所指结点 
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}else{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next=pa?pa:pb; // 将非空表的剩余段插入到pc所指结点之后
	free(LB); 
}

void ResponseCode(Status Code) {
	switch(Code) {
		case OK:
			printf("Suc\n");
			break;
		case ERROR:
			printf("E\n");
			break;
		case OVERFLOW:
			printf("OVERFLOW\n");
			break;
		default:
			printf("No Status\n");
			break;
	}
}

void InitListData(LinkList L,int length,int data[]){
	int i;
	for(i=0;i<=length-1;i++){
		ListInsert(L,i+1,data[i]);
	}
}

void InitList_LA_LB(LinkList &LA,LinkList &LB){
	InitList(LA);
	InitList(LB);
	InitListData(LA,4,La_data);
	InitListData(LB,7,Lb_data);
}

void TraverList(LinkList L){
	LinkList p=L->next;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

void Unit(){
	LinkList LA,LB,LC;
	InitList_LA_LB(LA,LB);
	TraverList(LA);
	TraverList(LB);
	MergeList_L(LA,LB,LC);
	TraverList(LC);
}

int main(){
	Unit();
}
