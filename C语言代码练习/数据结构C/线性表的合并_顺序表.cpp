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

void MergeList(SqList &LA,SqList LB) { // �ϲ�
	// ���������Ա�LB�е�����LA������Ԫ�ز��뵽LA��
	int i;
	ElemType e;
	int m=LA.length;
	// �������ȡ������
	// �����++LA.length ��һ��InsertList�ӣ��ڶ���LA.length��

	for(i=1; i<=LB.length; i++) {
		GetElem(LB,i,e);
		if(!LocateElem(LA,e)) {
			InsertList(LA,++m,e);
		}
	}
}

void MergeList_Sq(SqList LA,SqList LB,SqList &LC) {
	// ��֪˳�������LA��LB��Ԫ�ذ�ֵ�ǵݼ�����
	// �鲢LA��LB�õ��µ�˳�������LC��LC��Ԫ��Ҳ��ֵ�ǵݼ�����
	LC.length=LA.length+LB.length; // �±���Ϊ���ϲ�������֮��
	LC.e=(ElemType*)malloc(LC.length*sizeof(ElemType));
	ElemType *pc=LC.e; 	// ָ��pcָ���±��һ��Ԫ��
	ElemType *pa=LA.e,*pb=LB.e;  // ָ��pa��pb�ĳ�ֵ�ֱ�ָ��������ĵ�һ��Ԫ��
	ElemType *pa_last=LA.e+LA.length-1,*pb_last=LB.e+LB.length-1; //
	while((pa<=pa_last)&&(pb<=pb_last)) { // LA��LB��δ�����β
		if((*pa<=*pb))
			*pc++=*pa++; // ���Ρ�ժȡ��������ֵ��С�Ľ����뵽LC�����
		else
			*pc++=*pb++;
	}
	while(pa<=pa_last)
		*pc++=*pa++; // LB�����β�����ν�LA��ʣ��Ԫ�ز���LC�����
	while(pb<=pb_last)
		*pc++=*pb++; // LA�����β�����ν�LB��ʣ��Ԫ�ز���LC�����
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

	// ���þ���ĳһ������Ŀ�꣩��һ�������������õĲ�����Ա���ֱ�Ӳ�����ȫһ��
	// ����������ֱ�Ӹı��������ı���������
	// ��InsertListҲ�����ã�ͨ��InsertList���������ı�InitList_LA_LB������
	// ��InsertList_LA_LB�ı���������������
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
