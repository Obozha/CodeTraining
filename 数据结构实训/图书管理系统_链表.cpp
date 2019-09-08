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

typedef struct {
	char pName[50];
	int count;
} Publisher;

typedef struct PNode {
	Publisher data;
	struct PNode *next;
} PNode;


typedef struct  {
	char aName[50];
	int count;
} Author;

typedef struct ANode {
	Author data;
	struct ANode *next;
} ANode;

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

Book BookFactory(const char*no,const char*bookName,const char*author,const char*publisher,float price) {
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

//int ListLocate(LNode *L,LNode* p){
//
//	while(){
//
//	}
//}

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
	JudgeResponseCode(SuperListInsert(p,1,"001","JAVA","����","�廪������",520.0));
	JudgeResponseCode(SuperListInsert(p,2,"002","VUE.JS","����","��ҵ������",320.0));
	JudgeResponseCode(SuperListInsert(p,3,"003","C++","����","���������",700.0));
	JudgeResponseCode(SuperListInsert(p,4,"004","Asp.Net","����","�ߵȽ���������",660.0));
	JudgeResponseCode(SuperListInsert(p,5,"005","���������","С��","A������",780.0));
	JudgeResponseCode(SuperListInsert(p,6,"006","���ݽṹ","С��","A������",680.0));
	JudgeResponseCode(SuperListInsert(p,7,"007","���������ϵͳ","С��","B������",220.0));
	JudgeResponseCode(SuperListInsert(p,8,"008","���ݽṹ","С��","֣�������",140.0));
	JudgeResponseCode(SuperListInsert(p,9,"009","C++�����ŵ�����","С��","���Ϲ��̳�����",380.0));
	JudgeResponseCode(SuperListInsert(p,10,"010","C++�����ŵ�����","С��","���Ϲ��̳�����",180.0));
	JudgeResponseCode(SuperListInsert(p,11,"011","C++�����ŵ�����","С��","���Ϲ��̳�����",180.0));
	JudgeResponseCode(SuperListInsert(p,12,"012","��׿�����ŵ�����","С��","A������",180.0));
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
		fprintf(pf,"%s %s %s %s %f\n",p->data.no,p->data.bookName,p->data.author,p->data.publisher,p->data.price);
		p=p->next;
		count++;
	}
	cout<<"����"<<count<<"������"<<endl;
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

void Statistics(LNode *L) {
	// ͳ��
	int inputOption;
	while(1) {
		cout<<"1.ͳ�Ƴ�����ͼ�������������������� 2.ͳ�����߳���ͼ����������������� 3.�˳�"<<endl;
		cin>>inputOption;
		if(inputOption==3) {
			break;
		}
		switch(inputOption) {
			case 1: {
				// ͳ�Ƴ�����
				PNode *waitSort=new PNode;
				LNode *p=L->next;
				PNode *pw=waitSort;
				PNode *pre=waitSort;
				strcpy(pw->data.pName,"###");
				pw->next=NULL;
				pw->data.count=0;
				while(p) {
					int flag=1;
					while(pw) {
						if(strcmp(pw->data.pName,p->data.publisher)==0) {
							flag=0;
						}
						pre=pw;
						pw=pw->next;
					}

					if(flag==1) {
						PNode *q=new PNode;
						strcpy(q->data.pName,p->data.publisher);
						q->next=NULL;
						q->data.count=0;
						pre->next=q;
					}
					pw=waitSort->next;
					p=p->next;
				}
				pw=waitSort->next;
				p=L->next;
				while(pw) {
					p=L->next;
					while(p) {
						if(strcmp(pw->data.pName,p->data.publisher)==0) {
							pw->data.count++;
						}
						p=p->next;
					}
					pw=pw->next;
				}
				pw=waitSort->next;
				Publisher t;
				for (PNode *temp = waitSort->next; temp->next != NULL; temp = temp->next) {
					for (PNode *pn = waitSort->next; pn->next != NULL; pn = pn->next) {
						if (pn->data.count > pn->next->data.count) {
							t = pn->data;
							pn->data = pn->next->data;
							pn->next->data = t;
						}
					}
				}
				while(pw) {
					cout<<pw->data.pName<<":"<<pw->data.count<<endl;;
					pw=pw->next;
				}
				break;
			}
			case 2: {
				// ͳ�Ƴ�����
				ANode *waitSort=new ANode;
				LNode *p=L->next;
				ANode *pw=waitSort;
				ANode *pre=waitSort;
				strcpy(pw->data.aName,"###");
				pw->next=NULL;
				pw->data.count=0;
				while(p) {
					int flag=1;
					while(pw) {
						if(strcmp(pw->data.aName,p->data.author)==0) {
							flag=0;
						}
						pre=pw;
						pw=pw->next;
					}

					if(flag==1) {
						ANode *q=new ANode;
						strcpy(q->data.aName,p->data.author);
						q->next=NULL;
						q->data.count=0;
						pre->next=q;
					}
					pw=waitSort->next;
					p=p->next;
				}
				pw=waitSort->next;
				p=L->next;
				
				while(pw) {
					p=L->next;
					while(p) {

						if(strcmp(pw->data.aName,p->data.author)==0) {
							pw->data.count++;
						}
						p=p->next;
					}
					pw=pw->next;
				}
				pw=waitSort->next;
				Author t;
				for (ANode *temp = waitSort->next; temp->next != NULL; temp = temp->next) {
					for (ANode *pn = waitSort->next; pn->next != NULL; pn = pn->next) {
						if (pn->data.count < pn->next->data.count) {
							t = pn->data;
							pn->data = pn->next->data;
							pn->next->data = t;
						}
					}
				}
				while(pw) {
					cout<<pw->data.aName<<":"<<pw->data.count<<endl;;
					pw=pw->next;
				}
				break;
			}
			case 3:
				break;
			default:
				cout<<"��������������"<<endl;
				break;
		}
	}
}

Status AddNewBook(LNode* L) {
	float price;
	int flag; // ���no
	LNode *p=L->next;
	char name[50],au[50],pub[50],no[50];

	cout<<"��ֱ�������š����������ߣ�1�����������硢�۸��������"<<endl;
	int length=ListLength(L);
	cin>>no>>name>>au>>pub>>price;
	while(1) {
		flag=1;
		while(p) {
			if(strcmp(no,p->data.no)==0) {
				flag=0;
				break;
			}
			p=p->next;
		}
		p=L->next;
		if(flag==0) {
			cout<<"����ظ�,�������������:";
			cin>>no;
		} else {
			break;
		}
	}
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

Status ChangeBookInfo(LNode* L) {
	LNode* p=L->next;
	char inputNo[50];
	int inputOption=0,flag=0;
	cout<<"��������Ҫ�޸ĵ����"<<endl;
	cin>>inputNo;
	while(p) {
		if(strcmp(p->data.no,inputNo)==0) {
			break;
		}
		p=p->next;
	}
	if(p) {
		while(1) {
			cout<<"��������Ҫ�޸ĵ����� 1.���� 2.���� 3.������ 4.��Ǯ 5.�˳�"<<endl;
			cin>>inputOption;

			switch(inputOption) {
				case 1:
					char bookname[50];
					cout<<"����������:";
					cin>>bookname;
					strcpy(p->data.bookName,bookname);
					// �޸�����
					break;
				case 2:
					char author[50];
					cout<<"����������:";
					cin>>author;
					strcpy(p->data.author,author);
					// �޸�����
					break;
				case 3:
					char publisher[50];
					cout<<"�����������:";
					cin>>publisher;
					strcpy(p->data.publisher,publisher);
					// �޸ĳ�����
					break;
				case 4:
					float price;
					cout<<"������۸�:";
					cin>>price;
					p->data.price=price;
					// �޸ļ�Ǯ
					break;
				case 5:
					break;
				default:
					cout<<"��������������"<<endl;
					break;
			}
			if(inputOption==5) {
				WriteStructToFile(L);
				return OK;
				break;
			}
		}
	} else {
		cout<<"û���ҵ����"<<endl;
		return ERROR;
	}
}

void DeleteBookInfo(LNode* L) {
	char inputNo[50];
	int intOption=0;
	int i=1;
	LNode* p;
	LNode* pre=new LNode;
	while(1) {
		cout<<"��������Ҫɾ������Ϣ 1.��� 2.���� 3.�˳�"<<endl;
		cin>>intOption;
		if(intOption==3) {
			break;
		}
		switch(intOption) {
			case 1:
				// �����ɾ��
				cout<<"���������:";
				cin>>inputNo;
				p=L->next;
				i=1;
				while(p) {
					if(strcmp(p->data.no,inputNo)==0) {
						break;
					}
					p=p->next;
					i++;
				}
				if(p) {
					ListDelete(L,i);
					WriteStructToFile(L);
					cout<<"ɾ���ɹ�"<<endl;
				} else {
					cout<<"ɾ��ʧ��,û���ҵ��鼮��Ϣ";
				}
				break;
			case 2: {
				// ������ɾ��
				char bookName[50];
				int flag=0;
				cout<<"����������:";
				cin>>bookName;
				p=L->next;
				pre=L;
				while(p) {
					if(strcmp(p->data.bookName,bookName)==0) {
						pre->next=p->next;
						free(p);
						p=pre;
						flag=1;
					}
					pre=p;
					p=p->next;
				}
				if(flag==1) {
					WriteStructToFile(L);
					cout<<"ɾ���ɹ�"<<endl;
				} else {
					cout<<"û���ҵ���Ҫ�ҵ����鼮"<<endl;
				}
				break;
			}
			case 3:
				break;
			default:
				cout<<"��������������"<<endl;
				break;
		}
	}

}

void SearchBook(LNode* L) {
	LNode* p;
	int inputOption=0;
	while(1) {
		cout<<"�����������Ϣ 1.��� 2.���� 3.�˳�"<<endl;
		cin>>inputOption;
		if(inputOption==3) {
			break;
		}
		switch(inputOption) {
			case 1:
				// ͨ����ž�ȷ����
				char inputNo[50];
				p=L->next; 
				cout<<"���������:";
				cin>>inputNo;
				while(p) {
					if(strcmp(inputNo,p->data.no)==0) {
						break;
					};
					p=p->next;
				}
				if(p) {
					printf("%-15s|%-15s|%-15s|%-15s|%-2.0f|\n",p->data.no,p->data.bookName,p->data.author,p->data.publisher,p->data.price);
				} else {
					cout<<"û�ҵ�"<<endl;
				}
				break;
			case 2: {
				char bookName[50];
				p=L->next; 
				int i=1; 
				int flag=0,count=0;
				cout<<"����������:";
				cin>>bookName;
				while(p) {
					if(strcmp(bookName,p->data.bookName)==0) {
						printf("%-15s|%-15s|%-15s|%-15s|%-2.0f|\n",p->data.no,p->data.bookName,p->data.author,p->data.publisher,p->data.price);
						flag=1;
						
						count++;
						
						int sum=0;
						for(int a=i;a<ListLength(L),a++){
							sum+=(a-1);
						}
						
					};
					p=p->next;
					i++;
				}
				if(flag==0) {
					cout<<"û�ҵ�"<<endl;
				}
				cout<<"���ҳ���Ϊ"<<count<<endl;
				// ͨ��������ȷ����
				break;
			}
			default:
				cout<<"��������������"<<endl;
				break;
		}
	}
}

void SearchBookByPrice(LNode* L) {
	float min=0,max=0;
	LNode *p=L->next;
	LNode *waitSortList=new LNode;
	InitHeadNode(waitSortList);
	LNode *pw=waitSortList;
	cout<<"������һ����С�����ļ۸�:";
	cin>>min>>max;
	while(p) {
		if(p->data.price<=max&&p->data.price>=min) {
			pw->next=p;
			pw=pw->next;
		}
		p=p->next;
	}
	Book t;
	pw->next=NULL;
	for (LNode *temp = waitSortList->next; temp->next != NULL; temp = temp->next) {
		for (LNode *p = waitSortList->next; p->next != NULL; p = p->next) {
			if (p->data.price < p->next->data.price) {
				t = p->data;
				p->data = p->next->data;
				p->next->data = t;
			}
		}
	}
	AccessNodesData(waitSortList);
}

void SearchBookByAuthor(LNode* L) {
	char author[50];
	LNode *p=L->next;
	LNode *waitSortList=new LNode;
	InitHeadNode(waitSortList);
	LNode *pw=waitSortList;
	cout<<"������һ����������:";
	cin>>author;
	while(p) {
		if(strcmp(author,p->data.author)==0) {
			pw->next=p;
			pw=pw->next;
		}
		p=p->next;
	}
	Book t;
	pw->next=NULL;
	for (LNode *temp = waitSortList->next; temp->next != NULL; temp = temp->next) {
		for (LNode *p = waitSortList->next; p->next != NULL; p = p->next) {
			if (p->data.price > p->next->data.price) {
				t = p->data;
				p->data = p->next->data;
				p->next->data = t;
			}
		}
	}
	AccessNodesData(waitSortList);
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


}

void Console() {
	cout<<"��ӭ����ͼ��������Ver1.0�汾"<<endl;

	LNode *p;  // pΪָ��LNode��ָ����
	LNode **q=&p; // qָ��ָ���ָ��
	InitList(q);
	ReadStructFromFile(p);
	while(1) {
		int input=0;
		cout<<"1.����ͼ��"<<
		    endl<<"2.�޸�ͼ����Ϣ"<<
		    endl<<"3.ɾ��ָ��ͼ��"<<
		    endl<<"4.��ѯͼ����Ϣ"<<
		    endl<<"5.���ռ۸�Χ����"<<
		    endl<<"6.����ĳ�����߳����������Ϣ�����۸�������� "<<
		    endl<<"7.����ģ������"<<
		    endl<<"8 ���ͼ��������Ϣ"<<
		    endl<<"9.ͳ��"<<endl<<endl;
		cin>>input;
		switch(input) {
			case 1:
				// ����������ͼ�顣
				AddNewBook(p);
				break;
			case 2:
				if(ChangeBookInfo(p)==OK) {
					cout<<"�޸ĳɹ�"<<endl;
				} else {
					cout<<"�޸�ʧ��"<<endl;
				}
				// �����޸�ĳ��ͼ����Ϣ����Ų��ܸģ���
				break;
			case 3:
				DeleteBookInfo(p);
				// ����ɾ��ĳЩͼ����Ϣ���ֱ���š���������ɾ������
				break;
			case 4:
				SearchBook(p);
				// ���԰���Ż��������о�ȷ���ң�����������ʱ������ж౾ͼ�飬��ȫ�����ҳ��������������ҳ��ȣ���
				break;
			case 5:
				SearchBookByPrice(p);
				// ���԰��۸�Χ���в��ң�������۸����������
				break;
			case 6:
				SearchBookByAuthor(p);
				// ����ĳ�����߳��������ͼ����Ϣ�����۸����������
				break;
			case 7:
				// ���԰���������ģ�����ҡ�
				break;
			case 8:
				// �������ͼ����Ϣ��
				if(ReadStructFromFile(p)==OK) {
					AccessNodesData(p);
				}
				break;
			case 9:
				Statistics(p);
				// ͳ�ơ�
				break;
			default:
				cout<<"�����������������"<<endl;
				break;
		}
	}
}

int main() {
	Unit_v3();
	Console();
}
