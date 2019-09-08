#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 200

/*
 * ʹ�����Ա���� ����Ԫ�صĲ��룬ɾ�������£���ѯ
 * �߼��ṹ�����Խṹ������ṹ��˳�򴢴� -> 
 * 
*/ 

typedef int Status;
typedef struct{
	char no[20];	// ͼ��ISBN 
	char name[50];  // ͼ������ 
	float price;    // ͼ��۸� 
}Book;

typedef struct{
	Book *elem; // �洢�ռ�Ļ���ַ 
	int length; // ͼ����е�ǰͼ����� 
}SqList;        // ͼ���Ĵ洢�ṹ����ΪsqList 

// �ṹ������������Ҳ��ʹ��ֵ���ݷ�ʽ 

void JudgeResponseCode(Status);
Status InitList(SqList *L);
Status GetElem(SqList L,int i,Book *e);
Status ListInsert(SqList* L,int i,Book e);
Status SuperListInsert(SqList* L,int i,const char *no,const char *name,float price);
Status ListDelete(SqList *L,int i);
Status ListUpdate(SqList*L,int i,const char* no,const char*name,float price);
Status ListUpdateName(SqList* L,int i,const char *name);
Status ListUpdateNo(SqList* L,int i,const char *name);


int LocateElem(SqList,const char*no);

void QueryAllData(SqList L);
void JudgeResponseCode(Status ResponseCode);
void UnitTest();

/*
 * ��ʼ��List  
*/
Status InitList(SqList *L){
	// ����һ���յ�˳���L
	L->elem=(Book*)malloc(MAXSIZE*sizeof(Book)); // Ϊ˳������һ����СΪMAXSIZE������ռ� 
	if(!(L->elem))
		exit(OVERFLOW);	// �洢����ʧ���˳�
	L->length=0;
	return OK; 
}

//void CreatList(SqList *L,int n){
//	int i;
//	srand(time(0)); // ������������� 
//	for(i=0;i<n;i++){ // ��˳���L���n��[1,100]�ڵ�������� 
//		L->elem[i]=rand()%100+1; 
//	}
//}

/*
 * Listȡֵ 
*/
Status GetElem(SqList L,int i,Book *e){
	if(i<1||i>L.length) // �ж�i�Ƿ����
		return ERROR;
	*e=L.elem[i-1]; // elem[i-1]��Ԫ�洢�ĵ�i������Ԫ�� 
	return OK; 
}

/*
 * List�������� 
*/
Status ListInsert(SqList* L,int i,Book e){
	// ��˳���L�е�i��λ�ò����µ�Ԫ��e��iֵ�Ϸ���Χ�� 1<=i<=L.length+1
	int j;
	if((i<1)||(i>L->length+1))
		return ERROR;
	if(L->length==200)
		return ERROR;
	for(j=(L->length-1);j>=i-1;j--){
		L->elem[j+1]=L->elem[j]; // ����λ��֮���Ԫ�غ��� 
	}
	L->elem[i-1]=e; // ����Ԫ��e�����i��λ��
	++(L->length);
	return OK; 
}

/*
 * List���������汾* 
 */ 
Status SuperListInsert(SqList* L,int i,const char *no, const char* name,float price){ // ע���ַ���Ҫ�� const char *name 
	Book book;
	strcpy(book.name,name);
	strcpy(book.no,no);
	book.price=price;
	JudgeResponseCode(ListInsert(L,i,book));
}

/*
 * Listɾ�����Ϊi��Ԫ�� 
*/
Status ListDelete(SqList *L,int i){
	// ��˳���L��ɾ����i��Ԫ�أ�iֵ�ĺϷ���Χ�� 1<=i<=L.length
	int j;
	if((i<1)||(i>L->length))
		return ERROR; // iֵ���Ϸ�
	for(j=i;j<=L->length-1;j++){
		printf("%s ----> %s",L->elem[j].name,L->elem[j-1].name);
		L->elem[j-1]=L->elem[j];
		
		
	} 
	--L->length;
	return OK;
} 

/*
 * List���¼�¼  [���԰汾]
*/
Status ListUpdateAll(SqList* L,int i,const char*no,const char* name,float price){
	strcpy(L->elem[i].name,name);
	strcpy(L->elem[i].no,no);
	L->elem[i].price=price;	
}

Status ListUpdateName(SqList* L,int i,const char *name){
	// UpdateName
}

Status ListUpdateNo(SqList *L,int i,const char *name){
	// UpdateNo
}

/*
 * Listͨ��no��λ 
 */
int LocateElem(SqList L,const char* no){
	// ��˳���L�в���Ϊe������Ԫ�أ����������
	int i;
	for(i=0;i<L.length;i++){
		if(strcmp(no,L.elem[i].no)==0)
		{
			return i+1; // ���ҳɹ����������1 
		}
	} 
	return 0; // ����ʧ�ܣ�����0 
}

/*
 * List������������ 
 */ 
void QueryAllData(SqList L){
	printf("Query All your data ...\n");
	int i;
	for(i=0;i<L.length;i++){
		printf("%s %s %.0f\n",L.elem[i].name,L.elem[i].no,L.elem[i].price);
	}
}

/*
 * Listͨ�����ص�״̬�����״̬ 
 */ 
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

/*
 * CUnit C�������Ƶ�Ԫ���� 
 * 1.�ȳ�ʼ��List 
 * 2.���ָ��List��ָ��
 * 3.���롢���� 
 */
void UnitTest(){
	SqList L;
	SqList *pList;
	pList=&L;
	InitList(pList);
	// �ȳ�ʼ��List�ռ� 
	SuperListInsert(pList,1,"10086","Super Python",38.5);
	SuperListInsert(pList,2,"10087","C program",39.5);
	SuperListInsert(pList,3,"10088","Thinking in Java",48.5);
	// ��������	
	QueryAllData(L);
	// �������� 
	printf("\n%d\n",LocateElem(L,"10088"));	
	// ɾ������ 
	JudgeResponseCode(ListDelete(pList,3));
	// ��ѯ���� 
	Book *e;
	GetElem(L,1,e);
	QueryAllData(L);
	
	printf("��ѯ����Ϊ:\n"); 
	printf("%s %s",e->name,e->no);
}

int main(){
	UnitTest();
}
