#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 100;

typedef int ElemType;
typedef int Status;

typedef struct {
	ElemType *e;
	int length;
} SqList;

void ResponseCode(Status Code);

Status InitList(SqList &L) {
	L.e=(ElemType*)malloc(sizeof(ElemType));
	if(!L.e) {
		return ERROR;
	}
	L.length=0;
	return OK;
}

Status InsertList(SqList &L,int i,ElemType e) {
	if(i<1||i>L.length+1) {
		return ERROR;
	}
	int j=0;
	for(j=L.length-1; j>=i-1; j--) {
		L.e[j+1]=L.e[j];
	}
	L.e[i-1]=e;
	L.length++;
	return OK;
}

Status GetElem(SqList L,int i,ElemType &e) {
	if(i<1||i>L.length) {
		return ERROR;
	}
	e=L.e[i-1];
	return OK;
}

int LocateElem(SqList L,ElemType e) {
	int i;
	for(i=0; i<L.length; i++) {
		if(L.e[i]==e) {
			return i+1;
		}
	}
	return 0;
}

void MergeList(SqList &LA,SqList LB) { // 合并
	// 将所有线性表LB中但不在LA的数据元素插入到LA中
	int i;
	ElemType e;
	int m=LA.length;
	// 这个必须取出长度
	// 如果是++LA.length 第一是InsertList加，第二是LA.length加

	for(i=1; i<=LB.length; i++) {
		GetElem(LB,i,e);
		if(!LocateElem(LA,e)) {
			InsertList(LA,++m,e);
		}
	}
}

void MergeList_Sq(SqList LA,SqList LB,SqList &LC) {
	// 已知顺序有序表LA和LB的元素按值非递减排列
	// 归并LA和LB得到新的顺序有序表LC，LC的元素也按值非递减排列
	LC.length=LA.length+LB.length; // 新表长度为待合并两表长度之和
	LC.e=(ElemType*)malloc(LC.length*sizeof(ElemType));
	ElemType *pc=LC.e; 	// 指针pc指向新表第一个元素
	ElemType *pa=LA.e,*pb=LB.e;  // 指针pa和pb的初值分别指向两个表的第一个元素
	ElemType *pa_last=LA.e+LA.length-1,*pb_last=LB.e+LB.length-1; //
	while((pa<=pa_last)&&(pb<=pb_last)) { // LA和LB均未到达表尾
		if((*pa<=*pb))
			*pc++=*pa++; // 依次“摘取”两表中值较小的结点插入到LC的最后
		else
			*pc++=*pb++;
	}
	while(pa<=pa_last)
		*pc++=*pa++; // LB到达表尾，依次将LA的剩余元素插入LC的最后
	while(pb<=pb_last)
		*pc++=*pb++; // LA到达表尾，依次将LB的剩余元素插入LC的最后
}

void InitList_LA_LB(SqList &LA,SqList &LB) {
	ResponseCode(InitList(LA));
	ResponseCode(InsertList(LA,1,3));
	ResponseCode(InsertList(LA,2,5));
	ResponseCode(InsertList(LA,3,8));
	ResponseCode(InsertList(LA,4,11));

	ResponseCode(InitList(LB));
	ResponseCode(InsertList(LB,1,2));
	ResponseCode(InsertList(LB,2,6));
	ResponseCode(InsertList(LB,3,8));
	ResponseCode(InsertList(LB,4,9));
	ResponseCode(InsertList(LB,5,11));
	ResponseCode(InsertList(LB,6,15));
	ResponseCode(InsertList(LB,7,20));

	// 引用就是某一变量（目标）的一个别名，对引用的操作与对变量直接操作完全一样
	// 这里引用是直接改变主函数的变量的内容
	// 在InsertList也有引用，通过InsertList的引用来改变InitList_LA_LB的引用
	// 而InsertList_LA_LB改变了主函数的引用
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

void TraverseList(SqList L) {
	int i;
	for(i=0; i<L.length; i++) {
		printf("%d ",L.e[i]);
	}
	printf("\n");
}

void Unit() {
	SqList LA,LB,LC;
	InitList_LA_LB(LA,LB);
	MergeList_Sq(LA,LB,LC);
	TraverseList(LC);
}

int main() {
	Unit();
}
