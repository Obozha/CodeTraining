#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 200

typedef int Status;
typedef struct {
	char no[50];
	char bookName[50];
	char author[50];
	char publisher[50];
	float price;
} Book;

typedef struct LNode {
	Book data; // ������
	struct LNode *next; // ָ����
} LNode,*LinkList;
// *LinkListΪLnode���͵�ָ��

struct Publisher {
	char pName[15];
	int count;
};

struct Author {
	char aName[15];
	int count;
};

// ȷ����һ�������̣�Ȼ��ÿѡ��һ���ͱ���һ�鲻ͬ�����������

Status ClearList(LinkList L);
Status DestoryList(LinkList L);
Status GetElem(LinkList L,int i,Book *e);
Status InitList(LNode **L);
Status InitHeadNode(LNode *L);
Status ListInsert(LNode *L,int i,Book e);
Status SuperListInsert(LNode *L,const char* bookName,const char* no,float price);

int ListLength(LinkList L);
int ListEmpty(LinkList L);

void AccessNodesData(LNode* L);
void BatchInsert(LNode *p);
void CreateList_F(LinkList *L,int n);
void JudgeResponseCode(Status ResponseCode);
void Unit();

Book BookFactory(const char*no,const char*bookName,const char*author,const char*publisher,float price){
	Book book;
	strcpy(book.no,no);
	strcpy(book.bookName,bookName);
	strcpy(book.author,author);
	strcpy(book.publisher,publisher);
	book.price=price;
	return book;
}

/*
 * �������ʼ��ͷ�ڵ�
*/
Status InitList(LNode **L) {
	*L=(LNode*)malloc(sizeof(LNode));
	if(*L==NULL) {
		printf("����ռ�ʧ��");
	}
	if(InitHeadNode(*L)==OK) {
		cout<<"�ɹ���ʼ��ͷ���"<<endl<<endl;
	}
	(*L)->next=NULL;
	return OK;
}

/*
 * �������ʼ��ͷ�ڵ�
*/
Status InitHeadNode(LNode *L) {
	Book BaseBookifm;
	strcpy(BaseBookifm.no,"���");
	strcpy(BaseBookifm.bookName,"����");
	strcpy(BaseBookifm.author,"����");
	strcpy(BaseBookifm.publisher,"������");
	BaseBookifm.price=0;
	L->data=BaseBookifm;
	// L->data=BaseBookifm
	// ������ֱ�Ӹ�ֵ
	return OK;
}

/*
 * �������س���
*/
int ListLength(LinkList L) {
	// ����L��Ԫ�ظ���
	LinkList p;
	p=L->next; // pָ���һ�����
	int i=0;
	while(p) { // ����������ͳ�ƽ����
		i++;
		p=p->next;
	}
	return i;
}

/*
 * �������Ƿ�Ϊ��
*/
int ListEmpty(LNode *L) {
	// ��LΪ�ձ�  ���򷵻�0
	if(L->next) { // �ǿ�
		return 0;
	} else {
		return 1;
	}
}

/*
 * �������Ƿ�Ϊ��
*/
Status DestoryList(LinkList L) {
	LinkList p;
	while(L) {
		p=L;
		L=L->next;
		free(p);
	}
}

Status ClearList(LinkList L) {
	// ��L����Ϊ�ձ�
	LinkList p,q;
	p=L->next; // pָ���һ�����
	while(p) {
		q=p->next;
		free(p);
		p=q;
	}
	L->next=NULL;
	return OK;
}

Status GetElem(LinkList L,int i,Book *e) {
	LinkList p=L->next; // ����ͷ�ڵ�
	int j=1;
	while(p&&j<i) { // ���ɨ�裬ֱ��pָ���i��Ԫ�� ��pΪ��
		p=p->next;
		++j;
	}
	if(!p||j>i)
		return ERROR;
	*e=p->data; // ȡ��i��Ԫ��
	return OK;
} // GetElem

Status ListInsert(LNode *L,int i,Book e) {
	LNode *p=L;
	int j=0;
	while(p&&j<i-1) {
		p=p->next;
		j++;  // Ѱ��i-1�����
	}
	if(!p||j>i-1) {
		return ERROR; //i���ڱ�+1����С��1
	}
	LNode *Node=(LNode*)malloc(sizeof(LNode));
	//����LNode�Ǿֲ���������ջ�����������ʱ��LNodeҲ��������
	// ���Բ���LNode Node�����ں����Ȼ���ò��뵥������

	// ʹ��malloc���ڶ������볤��Ϊ LNode�������ռ�
	// �������뵽һ�����
	// ������ϵͳ�����Զ����գ���Ҫ����Ա�Լ������ͷ�
	// �����Ϳ��Ա�֤��㲻�ᱻ����
	// ͬʱ����������Nodeָ�룬��Ϊ��ʱ�����ӵ�����һ���ڵ�ָ����
	// ��˵õ��˱���

	Node->data=e;
	Node->next=p->next;
	p->next=Node;

// ====================================
//  ����Ϊ�������
//	LNode N;
//	LNode *q=&N;
//	q->data=e;
//	q->next=p->next;
//	p->next=q;
//	printf("%s",p->next->data.name);
//	printf("%s",p->next->data.no);
//	printf("%f",p->next->data.price);
// ====================================
	return OK;
}

/*
 * Super Insert
 */
Status SuperListInsert(LNode *L,int i,const char* no,const char* bookName,const char* author,const char* publisher,float price) {
	Book book=BookFactory(no,bookName,author,publisher,price);
	if(ListInsert(L,i,book)==OK) {
		return OK;
	}
}

Status ListDelete(LinkList L,int i) {
	// �ڴ�ͷ���ĵ�����ɾ����i��Ԫ��
	LNode *p=L;
	int j=0;
	while((p->next)&&(j<i-1)) { // ���ҵ�i-1����㣬pָ��ý��
		p=p->next;
		j++;
	}
	if(!(p->next)||(j>i-1)) {	// ��i>n��i<1ʱ��ɾ��λ�ò�����
		return ERROR;
	}
	LNode* q=p->next;
	p->next=q->next;
	free(q);
	return OK;
}

//void CreateList_F(LinkList *L,int n) {
//	*L=(LNode*)malloc(sizeof(LNode));
//	(*L)->next=NULL; // �Ƚ���һ����ͷ���ĵ�����
//
//	InitHeadNode(*L); // ͷ�ڵ��ʼ��
//
//	int i;
//	for(i=n; i>0; i--) {
//		LNode *p=(LNode*)malloc(sizeof(LNode));
//		const char*no,*bookName,*author,*publisher;
//		// Ҫ�����ַ���ʹ���ַ����飬������ʹ���ַ�ָ��
//		float price;
//		cout<<"��������š����������ߣ�1�����������硢�۸�";
//		cin>>price;
//		printf("Log");
//		Book book;
//		book.no=no;
//		book.bookName=bookName;
//		book.author=author;
//		book.publisher=publisher;
//		book.price=price;
//		p->data=book;
//		p->next=(*L)->next;
//		(*L)->next=p;
//	}
//} // CreateList_F

//void CreateList_L(LinkList *L,int n) {
//	// ��λ������n��Ԫ�ص�ֵ��������ͷ���ĵ�����L
//	*L=(LNode*)malloc(sizeof(LNode));
//	(*L)->next=NULL;
//	InitHeadNode(*L);
//	LNode *r=*L;  // βָ��rָ��ͷ�ڵ�
//	int i;
//	for(i=0; i<n; i++) {
//		LNode *l=(LNode*)malloc(sizeof(LNode)); // �����½��
//		char bookName[50];
//		char no[20];
//		float price;
//		printf("������������ISBN���۸�");
//		scanf("%s %s %f",bookName,no,&price);
//		Book book;
//		strcpy(book.bookName,bookName);
//		strcpy(book.no,no);
//		printf("%s",book.bookName);
//		book.price=price;
//		// ����Ԫ��ֵ
//		printf("Log");
//		l->data=book;
//		l->next=NULL;
//		r->next=l; // ���뵽��β��
//		r=l; //rָ���µ�β���
//	}
//}


void AccessNodesData(LNode* L) {
	LNode* p=L;
	printf("ͷ�ڵ���ϢΪ��\n");
	printf("%-15s|%-15s|%-15s|%-15s|%-2.0f |\n",p->data.no,p->data.bookName,p->data.author,p->data.publisher,p->data.price);
	p=p->next; // �ܳ�ͷ�ڵ�
	do {
		printf("%-15s|%-15s|%-15s|%-15s|%-2.0f|\n",p->data.no,p->data.bookName,p->data.author,p->data.publisher,p->data.price);
		p=p->next;
	} while(p!=NULL); // !! ע����p!=NULL ������p->next!=NULL
}

//void SortPublisher(LNode* L) {
//	LNode* p=L;
//	p=p->next; // �ܳ�ͷ�ڵ�
//	int length=ListLength(L);
//	Publisher* pu=new Publisher[length];
//	pu[0].pName=p->data.publisher;
//	pu[0].count=0;
//	pu[0].count++;
//	for(int i=1; i<length; i++) {
//		pu[i].pName="###";
//		pu[i].count=0;
//	}
//	while(p) {
//		p=p->next;
//		int exist=1;
//		for(int i=0; i<length; i++) {
//			if(p->data.publisher==pu[i].pName) {
//				pu[i].count++;
//				exist=0;
//			}
//		}
//		if(exist=1) {
//			for(int i=0; i<length; i++) {
//				if(pu[i].count==0) {
//					pu[i].pName=p->data.publisher;
//					pu[i].count++;
//					break;
//				}
//			}
//		}
//	}
//	for(int i=1; i<length; i++) {
//		cout<<pu[i].pName<<endl;
//		cout<<pu[i].count<<endl;
//	}
//}

void JudgeResponseCode(Status ResponseCode) {
	switch(ResponseCode) {
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

void BatchInsert(LNode *p) {
	printf("==================================��ʼ������=====================================\n");
	JudgeResponseCode(SuperListInsert(p,1,"001","JAVA","����","�廪������",100.0));
	JudgeResponseCode(SuperListInsert(p,2,"002","VUE.JS","����","��ҵ������",200.0));
	JudgeResponseCode(SuperListInsert(p,3,"003","C++","����","���������",300.0));
	JudgeResponseCode(SuperListInsert(p,4,"004","Asp.Net","����","�ߵȽ���������",660.0));
	JudgeResponseCode(SuperListInsert(p,5,"005","���������","С��","A������",780.0));
	JudgeResponseCode(SuperListInsert(p,6,"006","���������ϵͳ","С��","B������",120.0));
	JudgeResponseCode(SuperListInsert(p,7,"007","���ݽṹ","С��","֣�������",140.0));
	JudgeResponseCode(SuperListInsert(p,8,"008","C++�����ŵ�����","С��","���Ϲ��̳�����",180.0));
	printf("��ǰһ����%d������\n",ListLength(p));
	printf("==================================��ʼ������=====================================\n\n");
}

Status WriteStructToFile(LNode* L) {
	LNode* p=L->next;
	FILE * pf;
	int count=0;
	if((pf=(fopen(".\\a.dat","w+")))==0)
		return ERROR;
	while(p) {
		fprintf(pf,"\n%s %s %s %s %f",p->data.no,p->data.bookName,p->data.author,p->data.publisher,p->data.price);
		p=p->next;
		count++;
	}
	cout<<"����9������"<<count<<"������"<<endl;
	fclose(pf);
	return OK;
}

Status ReadStructFromFile(LNode* L) {
	ClearList(L); 
	FILE * pf;
	if((pf=(fopen(".\\a.dat","r")))==0)
		return ERROR;
	Book b;
	int i=0;
	while(!feof(pf)) {
		int res=fscanf(pf,"%s%s%s%s%f",b.no,b.bookName,b.author,b.publisher,&b.price);
		if(res==-1)break;
		ListInsert(L,++i,b);
		// !Debug��Ҫ��
	}
	fclose(pf);
	return OK;
}

Status AddNewBook(LNode* L) {
	float price;
	char no[50],name[50],au[50],pub[50];
	LNode* p=L->next;
	cout<<"��ֱ�������š����������ߣ�1�����������硢�۸��������"<<endl;
	int length=ListLength(L);
	cin>>no>>name>>au>>pub>>price;
	Book e=BookFactory(no,name,au,pub,price);
	for(int i=0; i<length-1; i++) {
		p=p->next;
	}
	LNode* q=new LNode;
	q->data=e;
	p->next=q;
	q->next=NULL;
	WriteStructToFile(L);
}

void Unit() {
//	LNode l;	  // LNode�ṹ��
	LNode *p;  // pΪָ��LNode��ָ����
	LNode **q=&p; // qָ��ָ���ָ��

	/* ��ʼ��ָ����Ҫ���� ָ��ָ���ָ�룬ͨ��ָ��ָ���ָ�����ı�ָ��ĵ�ַ
	 * ������ͨ������ָ�봫��
	 */
	InitList(q);

	/*
	 * ������������
	 */
	BatchInsert(p);
	AccessNodesData(p);

	/*
	 * ���Ի��Ԫ��
	 */
	Book *b=(Book*)malloc(sizeof(Book));
	GetElem(p,3,b);
	printf("GetElem��ȡ������Ϊ:%s %s %.0f\n",b->bookName,b->no,b->price);

	/*
	 * ɾ��Ԫ��
	 */
	JudgeResponseCode(ListDelete(p,8));
	AccessNodesData(p);
}

void Unit_v2() {
	printf("Unit_V2\n");
	LNode q;
	LNode *p=&q;
	LNode **L=&p;
	//CreateList_L(L,3);
//	CreateList_F(L,3);

	AccessNodesData(*L);
}

void Unit_v3() {
	//	LNode l;	  // LNode�ṹ��
	LNode *p;  // pΪָ��LNode��ָ����
	LNode **q=&p; // qָ��ָ���ָ��

	/* ��ʼ��ָ����Ҫ���� ָ��ָ���ָ�룬ͨ��ָ��ָ���ָ�����ı�ָ��ĵ�ַ
	 * ������ͨ������ָ�봫��
	 */
	InitList(q);

	/*
	 * ������������
	 */
	BatchInsert(p);
	if(WriteStructToFile(p)==OK) {
		cout<<"д�����ݳɹ�"<<endl;
	}
	if(ReadStructFromFile(p)==OK) {
		cout<<"��ȡ���ݳɹ�"<<endl;
	}
	AccessNodesData(p);

//	Book book;
//	strcpy(book.no,"222");
//	strcpy(book.bookName,"IamComing");
//	strcpy(book.author,"zz");
//	strcpy(book.publisher,"test");
//	book.price=10;
//
//	AddNewBooks(p,book);
}

void Console() {
	cout<<"��ӭ����ͼ��������Ver1.0�汾"<<endl;

	LNode *p;  // pΪָ��LNode��ָ����
	LNode **q=&p; // qָ��ָ���ָ��
	InitList(q);
//
	ReadStructFromFile(p);

//	Book book;
//	strcpy(book.no,"222");
//	strcpy(book.bookName,"IamComing");
//	strcpy(book.author,"zz");
//	strcpy(book.publisher,"test");
//	book.price=10;
//
//	AddNewBooks(p,book);
//	AccessNodesData(p);

	while(1) {
		int input=0;
		cout<<"1.����ͼ��"<<
		endl<<"2.�޸�ͼ����Ϣ"<<
		endl<<"3.ɾ��ָ��ͼ��"<<
		endl<<"4.������Ų���"<<
		endl<<"5.�������߲���"<<
		endl<<"6.���ռ۸�Χ����"<<
		endl<<"7.����ĳ�����߳����������Ϣ�����۸�������� "<<
		endl<<"8.����ģ������"<<
		endl<<"9 ���ͼ��������Ϣ"<<
		endl<<"10.ͳ��"<<endl<<endl;
		cin>>input;
		switch(input) {
			case 1:
				// ����������ͼ�顣
				AddNewBook(p);
				break;
			case 2:
				// �����޸�ĳ��ͼ����Ϣ����Ų��ܸģ���
				break;
			case 3:
				// ����ɾ��ĳЩͼ����Ϣ���ֱ���š���������ɾ������
				break;
			case 4:
				// ����Ž��в��ң�Ҫ��ʹ�ö��ֲ��ҷ������������ҳ��ȣ�
				break;
			case 5:
				// �����߽��в��ң�����ж౾ͼ�飬��ȫ�����ҳ�����
				break;
			case 6:
				// ���԰��۸�Χ���в��ң�������۸������������
				break;
			case 7:
				// ����ĳ����������������ͼ����Ϣ�����۸��������
				break;
			case 8:
				// ����������ģ�����ҡ�
				break;
			case 9:
				// �������ͼ����Ϣ��
				if(ReadStructFromFile(p)==OK) {
					AccessNodesData(p);
				}
				break;
			case 10:
				// ͳ�ơ�
				break;
			
		}
	}
}

int main() {
	//Unit_v3();
	Console();
}




//LNode *LocateElem(LinkList L,Book e){
//	// ����L��ֵΪe������Ԫ�صĵ�ַ�����ҷ���NULL
//	LinkList p=L;
//	p=L->next;
//	while(p&&p->data!=e){
//		p=p->next;
//	}
//	return p;
//}

//int LocateElemNum(LinkList L,Book e){
//	// ����L��ֵΪe������Ԫ�ص�λ����ţ�����ʧ�ܷ���0
//	LinkList p=L->next;
//	int j=1;
//	while(p&&p->data!=e){
//		p=p->next;
//		j++;
//	}
//	if(p)
//		return j;
//	else
//		return 0;
//}

// ���Ծֲ���������������
//Book *hello(){
//	Book b;
//	b.price=20;
//	strcpy(b.name,"HelloWorld");
//	strcpy(b.no,"SSINK");
//	Book *p=&b;
//	return p;
//}
