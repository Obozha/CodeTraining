#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 200

/*
 * 使用线性表完成 数据元素的插入，删除，更新，查询
 * 逻辑结构是线性结构，储存结构是顺序储存 -> 
 * 
*/ 

typedef int Status;
typedef struct{
	char no[20];	// 图书ISBN 
	char name[50];  // 图书名字 
	float price;    // 图书价格 
}Book;

typedef struct{
	Book *elem; // 存储空间的基地址 
	int length; // 图书表中当前图书个数 
}SqList;        // 图书表的存储结构类型为sqList 

// 结构体做函数参数也是使用值传递方式 

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
 * 初始化List  
*/
Status InitList(SqList *L){
	// 创造一个空的顺序表L
	L->elem=(Book*)malloc(MAXSIZE*sizeof(Book)); // 为顺序表分配一个大小为MAXSIZE的数组空间 
	if(!(L->elem))
		exit(OVERFLOW);	// 存储分配失败退出
	L->length=0;
	return OK; 
}

//void CreatList(SqList *L,int n){
//	int i;
//	srand(time(0)); // 设置随机数种子 
//	for(i=0;i<n;i++){ // 向顺序表L填充n个[1,100]内的随机整数 
//		L->elem[i]=rand()%100+1; 
//	}
//}

/*
 * List取值 
*/
Status GetElem(SqList L,int i,Book *e){
	if(i<1||i>L.length) // 判断i是否合理
		return ERROR;
	*e=L.elem[i-1]; // elem[i-1]单元存储的第i个数据元素 
	return OK; 
}

/*
 * List表插入操作 
*/
Status ListInsert(SqList* L,int i,Book e){
	// 在顺序表L中第i个位置插入新的元素e，i值合法范围是 1<=i<=L.length+1
	int j;
	if((i<1)||(i>L->length+1))
		return ERROR;
	if(L->length==200)
		return ERROR;
	for(j=(L->length-1);j>=i-1;j--){
		L->elem[j+1]=L->elem[j]; // 插入位置之后的元素后移 
	}
	L->elem[i-1]=e; // 将新元素e放入第i个位置
	++(L->length);
	return OK; 
}

/*
 * List插入升级版本* 
 */ 
Status SuperListInsert(SqList* L,int i,const char *no, const char* name,float price){ // 注意字符串要用 const char *name 
	Book book;
	strcpy(book.name,name);
	strcpy(book.no,no);
	book.price=price;
	JudgeResponseCode(ListInsert(L,i,book));
}

/*
 * List删除序号为i的元素 
*/
Status ListDelete(SqList *L,int i){
	// 在顺序表L中删除第i个元素，i值的合法范围是 1<=i<=L.length
	int j;
	if((i<1)||(i>L->length))
		return ERROR; // i值不合法
	for(j=i;j<=L->length-1;j++){
		printf("%s ----> %s",L->elem[j].name,L->elem[j-1].name);
		L->elem[j-1]=L->elem[j];
		
		
	} 
	--L->length;
	return OK;
} 

/*
 * List更新纪录  [测试版本]
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
 * List通过no定位 
 */
int LocateElem(SqList L,const char* no){
	// 在顺序表L中查找为e的数据元素，返回其序号
	int i;
	for(i=0;i<L.length;i++){
		if(strcmp(no,L.elem[i].no)==0)
		{
			return i+1; // 查找成功，返回序号1 
		}
	} 
	return 0; // 查找失败，返回0 
}

/*
 * List遍历所有数据 
 */ 
void QueryAllData(SqList L){
	printf("Query All your data ...\n");
	int i;
	for(i=0;i<L.length;i++){
		printf("%s %s %.0f\n",L.elem[i].name,L.elem[i].no,L.elem[i].price);
	}
}

/*
 * List通过返回的状态码输出状态 
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
 * CUnit C语言自制单元测试 
 * 1.先初始化List 
 * 2.获得指向List的指针
 * 3.插入、遍历 
 */
void UnitTest(){
	SqList L;
	SqList *pList;
	pList=&L;
	InitList(pList);
	// 先初始化List空间 
	SuperListInsert(pList,1,"10086","Super Python",38.5);
	SuperListInsert(pList,2,"10087","C program",39.5);
	SuperListInsert(pList,3,"10088","Thinking in Java",48.5);
	// 插入数据	
	QueryAllData(L);
	// 遍历数据 
	printf("\n%d\n",LocateElem(L,"10088"));	
	// 删除数据 
	JudgeResponseCode(ListDelete(pList,3));
	// 查询数据 
	Book *e;
	GetElem(L,1,e);
	QueryAllData(L);
	
	printf("查询数据为:\n"); 
	printf("%s %s",e->name,e->no);
}

int main(){
	UnitTest();
}
