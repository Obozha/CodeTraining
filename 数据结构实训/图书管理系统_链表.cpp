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
	Book data; // 数据域
	struct LNode *next; // 指针域
} LNode,*LinkList;
// *LinkList为Lnode类型的指针

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

// 确定第一个出版商，然后，每选择一个就遍历一遍不同出版社的数组

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
 * 单链表初始化头节点
*/
Status InitList(LNode **L) {
	*L=(LNode*)malloc(sizeof(LNode));
	if(*L==NULL) {
		printf("申请空间失败");
	}
	if(InitHeadNode(*L)==OK) {
		cout<<"成功初始化头结点"<<endl<<endl;
	}
	(*L)->next=NULL;
	return OK;
}

/*
 * 单链表初始化头节点
*/
Status InitHeadNode(LNode *L) {
	Book BaseBookifm;
	strcpy(BaseBookifm.no,"书号");
	strcpy(BaseBookifm.bookName,"书名");
	strcpy(BaseBookifm.author,"作者");
	strcpy(BaseBookifm.publisher,"出版社");
	BaseBookifm.price=0;
	L->data=BaseBookifm;
	// L->data=BaseBookifm
	// 这里是直接赋值
	return OK;
}

/*
 * 单链表返回长度
*/
int ListLength(LinkList L) {
	// 返回L中元素个数
	LinkList p;
	p=L->next; // p指向第一个结点
	int i=0;
	while(p) { // 遍历单链表，统计结点数
		i++;
		p=p->next;
	}
	return i;
}

/*
 * 单链表是否为空
*/
int ListEmpty(LNode *L) {
	// 若L为空表，  否则返回0
	if(L->next) { // 非空
		return 0;
	} else {
		return 1;
	}
}

/*
 * 单链表是否为空
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
	// 将L重置为空表
	LinkList p,q;
	p=L->next; // p指向第一个结点
	while(p) {
		q=p->next;
		free(p);
		p=q;
	}
	L->next=NULL;
	return OK;
}

Status GetElem(LinkList L,int i,Book *e) {
	LinkList p=L->next; // 跳过头节点
	int j=1;
	while(p&&j<i) { // 向后扫描，直到p指向第i个元素 或p为空
		p=p->next;
		++j;
	}
	if(!p||j>i)
		return ERROR;
	*e=p->data; // 取第i个元素
	return OK;
} // GetElem

Status ListInsert(LNode *L,int i,Book e) {
	LNode *p=L;
	int j=0;
	while(p&&j<i-1) {
		p=p->next;
		j++;  // 寻找i-1个结点
	}
	if(!p||j>i-1) {
		return ERROR; //i大于表长+1或者小于1
	}
	LNode *Node=(LNode*)malloc(sizeof(LNode));
	//首先LNode是局部变量，在栈里，函数消亡的时候LNode也跟着消亡
	// 所以不能LNode Node声明在函数里，然后让插入单链表中

	// 使用malloc是在堆中申请长度为 LNode的连续空间
	// 进而申请到一个结点
	// 这个结点系统不会自动回收，需要程序员自己进行释放
	// 这样就可以保证结点不会被消亡
	// 同时即将消亡的Node指针，因为及时的链接到了上一个节点指针上
	// 因此得到了保留

	Node->data=e;
	Node->next=p->next;
	p->next=Node;

// ====================================
//  以下为错误代码
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
	// 在带头结点的单链表，删除第i个元素
	LNode *p=L;
	int j=0;
	while((p->next)&&(j<i-1)) { // 查找第i-1个结点，p指向该结点
		p=p->next;
		j++;
	}
	if(!(p->next)||(j>i-1)) {	// 当i>n或i<1时，删除位置不合理
		return ERROR;
	}
	LNode* q=p->next;
	p->next=q->next;
	free(q);
	return OK;
}

//void CreateList_F(LinkList *L,int n) {
//	*L=(LNode*)malloc(sizeof(LNode));
//	(*L)->next=NULL; // 先建立一个带头结点的单链表
//
//	InitHeadNode(*L); // 头节点初始化
//
//	int i;
//	for(i=n; i>0; i--) {
//		LNode *p=(LNode*)malloc(sizeof(LNode));
//		const char*no,*bookName,*author,*publisher;
//		// 要输入字符串使用字符数组，而不能使用字符指针
//		float price;
//		cout<<"请输入书号、书名、作者（1个）、出版社、价格";
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
//	// 正位序输入n个元素的值，建立带头结点的单链表L
//	*L=(LNode*)malloc(sizeof(LNode));
//	(*L)->next=NULL;
//	InitHeadNode(*L);
//	LNode *r=*L;  // 尾指针r指向头节点
//	int i;
//	for(i=0; i<n; i++) {
//		LNode *l=(LNode*)malloc(sizeof(LNode)); // 生成新结点
//		char bookName[50];
//		char no[20];
//		float price;
//		printf("请输入书名，ISBN，价格：");
//		scanf("%s %s %f",bookName,no,&price);
//		Book book;
//		strcpy(book.bookName,bookName);
//		strcpy(book.no,no);
//		printf("%s",book.bookName);
//		book.price=price;
//		// 输入元素值
//		printf("Log");
//		l->data=book;
//		l->next=NULL;
//		r->next=l; // 插入到表尾部
//		r=l; //r指向新的尾结点
//	}
//}


void AccessNodesData(LNode* L) {
	LNode* p=L;
	printf("头节点信息为：\n");
	printf("%-15s|%-15s|%-15s|%-15s|%-2.0f |\n",p->data.no,p->data.bookName,p->data.author,p->data.publisher,p->data.price);
	p=p->next; // 跑出头节点
	do {
		printf("%-15s|%-15s|%-15s|%-15s|%-2.0f|\n",p->data.no,p->data.bookName,p->data.author,p->data.publisher,p->data.price);
		p=p->next;
	} while(p!=NULL); // !! 注意是p!=NULL 而不是p->next!=NULL
}

//void SortPublisher(LNode* L) {
//	LNode* p=L;
//	p=p->next; // 跑出头节点
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
	printf("==================================初始化数据=====================================\n");
	JudgeResponseCode(SuperListInsert(p,1,"001","JAVA","张三","清华出版社",520.0));
	JudgeResponseCode(SuperListInsert(p,2,"002","VUE.JS","李四","工业出版社",320.0));
	JudgeResponseCode(SuperListInsert(p,3,"003","C++","王五","北大出版社",700.0));
	JudgeResponseCode(SuperListInsert(p,4,"004","Asp.Net","赵六","高等教育出版社",660.0));
	JudgeResponseCode(SuperListInsert(p,5,"005","计算机网络","小明","A出版社",780.0));
	JudgeResponseCode(SuperListInsert(p,6,"006","数据结构","小明","A出版社",680.0));
	JudgeResponseCode(SuperListInsert(p,7,"007","计算机操作系统","小红","B出版社",220.0));
	JudgeResponseCode(SuperListInsert(p,8,"008","数据结构","小蓝","郑大出版社",140.0));
	JudgeResponseCode(SuperListInsert(p,9,"009","C++从入门到放弃","小智","河南工程出版社",380.0));
	JudgeResponseCode(SuperListInsert(p,10,"010","C++从入门到放弃","小芳","河南工程出版社",180.0));
	JudgeResponseCode(SuperListInsert(p,11,"011","C++从入门到放弃","小梨","河南工程出版社",180.0));
	JudgeResponseCode(SuperListInsert(p,12,"012","安卓从入门到放弃","小明","A出版社",180.0));
	printf("当前一共有%d个数据\n",ListLength(p));
	printf("==================================初始化数据=====================================\n\n");
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
	cout<<"共有"<<count<<"条数据"<<endl;
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
		// !Debug重要性
	}
	fclose(pf);
	return OK;
}

void Statistics(LNode *L) {
	// 统计
	int inputOption;
	while(1) {
		cout<<"1.统计出版社图书出版总数，按升序输出 2.统计作者出版图书总数，按降序输出 3.退出"<<endl;
		cin>>inputOption;
		if(inputOption==3) {
			break;
		}
		switch(inputOption) {
			case 1: {
				// 统计出版社
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
				// 统计出版社
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
				cout<<"请重新输入数字"<<endl;
				break;
		}
	}
}

Status AddNewBook(LNode* L) {
	float price;
	int flag; // 检测no
	LNode *p=L->next;
	char name[50],au[50],pub[50],no[50];

	cout<<"请分别输入书号、书名、作者（1个）、出版社、价格五个部分"<<endl;
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
			cout<<"书号重复,请重新输入书号:";
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
	cout<<"请输入需要修改的书号"<<endl;
	cin>>inputNo;
	while(p) {
		if(strcmp(p->data.no,inputNo)==0) {
			break;
		}
		p=p->next;
	}
	if(p) {
		while(1) {
			cout<<"请输入需要修改的数据 1.书名 2.作者 3.出版社 4.价钱 5.退出"<<endl;
			cin>>inputOption;

			switch(inputOption) {
				case 1:
					char bookname[50];
					cout<<"请输入书名:";
					cin>>bookname;
					strcpy(p->data.bookName,bookname);
					// 修改书名
					break;
				case 2:
					char author[50];
					cout<<"请输入作者:";
					cin>>author;
					strcpy(p->data.author,author);
					// 修改作者
					break;
				case 3:
					char publisher[50];
					cout<<"请输入出版社:";
					cin>>publisher;
					strcpy(p->data.publisher,publisher);
					// 修改出版社
					break;
				case 4:
					float price;
					cout<<"请输入价格:";
					cin>>price;
					p->data.price=price;
					// 修改价钱
					break;
				case 5:
					break;
				default:
					cout<<"请重新输入数字"<<endl;
					break;
			}
			if(inputOption==5) {
				WriteStructToFile(L);
				return OK;
				break;
			}
		}
	} else {
		cout<<"没有找到书号"<<endl;
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
		cout<<"请输入需要删除的信息 1.书号 2.书名 3.退出"<<endl;
		cin>>intOption;
		if(intOption==3) {
			break;
		}
		switch(intOption) {
			case 1:
				// 按书号删除
				cout<<"请输入书号:";
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
					cout<<"删除成功"<<endl;
				} else {
					cout<<"删除失败,没有找到书籍信息";
				}
				break;
			case 2: {
				// 按书名删除
				char bookName[50];
				int flag=0;
				cout<<"请输入书名:";
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
					cout<<"删除成功"<<endl;
				} else {
					cout<<"没有找到需要找到的书籍"<<endl;
				}
				break;
			}
			case 3:
				break;
			default:
				cout<<"请重新输入数字"<<endl;
				break;
		}
	}

}

void SearchBook(LNode* L) {
	LNode* p;
	int inputOption=0;
	while(1) {
		cout<<"请输入查找信息 1.书号 2.书名 3.退出"<<endl;
		cin>>inputOption;
		if(inputOption==3) {
			break;
		}
		switch(inputOption) {
			case 1:
				// 通过书号精确查找
				char inputNo[50];
				p=L->next; 
				cout<<"请输入书号:";
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
					cout<<"没找到"<<endl;
				}
				break;
			case 2: {
				char bookName[50];
				p=L->next; 
				int i=1; 
				int flag=0,count=0;
				cout<<"请输入书名:";
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
					cout<<"没找到"<<endl;
				}
				cout<<"查找长度为"<<count<<endl;
				// 通过书名精确查找
				break;
			}
			default:
				cout<<"请重新输入数字"<<endl;
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
	cout<<"请输入一个最小和最大的价格:";
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
	cout<<"请输入一个作者名字:";
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
//	LNode l;	  // LNode结构体
	LNode *p;  // p为指向LNode的指针体
	LNode **q=&p; // q指向指针的指针

	/* 初始化指针需要给入 指向指针的指针，通过指向指针的指针来改变指针的地址
	 * 这里是通过二级指针传递
	 */
	InitList(q);

	/*
	 * 批量插入数据
	 */
	BatchInsert(p);
	AccessNodesData(p);

	/*
	 * 测试获得元素
	 */
	Book *b=(Book*)malloc(sizeof(Book));
	GetElem(p,3,b);
	printf("GetElem获取的数据为:%s %s %.0f\n",b->bookName,b->no,b->price);

	/*
	 * 删除元素
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
	//	LNode l;	  // LNode结构体
	LNode *p;  // p为指向LNode的指针体
	LNode **q=&p; // q指向指针的指针

	/* 初始化指针需要给入 指向指针的指针，通过指向指针的指针来改变指针的地址
	 * 这里是通过二级指针传递
	 */
	InitList(q);

	/*
	 * 批量插入数据
	 */
	BatchInsert(p);
	if(WriteStructToFile(p)==OK) {
		cout<<"写入数据成功"<<endl;
	}
	if(ReadStructFromFile(p)==OK) {
		cout<<"读取数据成功"<<endl;
	}
	AccessNodesData(p);


}

void Console() {
	cout<<"欢迎来到图书管理软件Ver1.0版本"<<endl;

	LNode *p;  // p为指向LNode的指针体
	LNode **q=&p; // q指向指针的指针
	InitList(q);
	ReadStructFromFile(p);
	while(1) {
		int input=0;
		cout<<"1.增加图书"<<
		    endl<<"2.修改图书信息"<<
		    endl<<"3.删除指定图书"<<
		    endl<<"4.查询图书信息"<<
		    endl<<"5.按照价格范围查找"<<
		    endl<<"6.查找某个作者出版的所有信息，按价格升序输出 "<<
		    endl<<"7.书名模糊查找"<<
		    endl<<"8 输出图书所有信息"<<
		    endl<<"9.统计"<<endl<<endl;
		cin>>input;
		switch(input) {
			case 1:
				// 可以增加新图书。
				AddNewBook(p);
				break;
			case 2:
				if(ChangeBookInfo(p)==OK) {
					cout<<"修改成功"<<endl;
				} else {
					cout<<"修改失败"<<endl;
				}
				// 可以修改某个图书信息（书号不能改）。
				break;
			case 3:
				DeleteBookInfo(p);
				// 可以删除某些图书信息（分别按书号、书名进行删除）。
				break;
			case 4:
				SearchBook(p);
				// 可以按书号或书名进行精确查找（按书名查找时，如果有多本图书，则全部查找出来，并输出其查找长度）。
				break;
			case 5:
				SearchBookByPrice(p);
				// 可以按价格范围进行查找（结果按价格降序输出）。
				break;
			case 6:
				SearchBookByAuthor(p);
				// 查找某个作者出版的所有图书信息，按价格升序输出。
				break;
			case 7:
				// 可以按书名进行模糊查找。
				break;
			case 8:
				// 输出所有图书信息。
				if(ReadStructFromFile(p)==OK) {
					AccessNodesData(p);
				}
				break;
			case 9:
				Statistics(p);
				// 统计。
				break;
			default:
				cout<<"输入错误，轻重新输入"<<endl;
				break;
		}
	}
}

int main() {
	Unit_v3();
	Console();
}
