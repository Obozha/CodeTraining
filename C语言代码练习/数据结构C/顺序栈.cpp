#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 100

typedef int Status;
typedef struct{
	char no[100];
	char name[50];
	float price;
}Book;

typedef struct{
	Book *base;
	Book *top;
	int stacksize;
}SqStack;

// 顺序栈初始化
// 构造一个空栈
// 步骤：
// (1) 分配空间并检查空间是否分配失败
//     若失败则返回错误
// (2) 设置栈底和栈顶指针
// S.top=S.base;
// (3) 设置栈大小 

/*
 * 创建一个空栈 
 */
Status InitStack(SqStack &S){
	S.base=(Book*)malloc(MAXSIZE*sizeof(Book)); // 初始化栈里的数据 
	if(!S.base)
		return OVERFLOW;
	S.top=S.base;								// 栈底和栈顶指向同一个位置 
	S.stacksize=MAXSIZE;						// 栈设置大小 
	return OK;
}

/*
 * 栈是否为空
 * 1就是空 
 * 0就是非空 
 */ 
int StackEmpty(SqStack S){
	if(S.top==S.base)
		return 1;
	else
		return 0;
}

/*
 * 栈的长度
 * 栈顶指针减去栈底指针
 * 栈顶指针总会超过数组当前数据的指针，为的是减去正好为长度值
 * 指针的计数也是 p+0 p+1 p+2 从0开始的 
 */ 
int StackLength(SqStack S){
	return S.top-S.base;
}

/*
 * 清空栈，不需要所有元素 
 * 注：这里只是将栈顶的指针指向了栈底，实际数据并没有消失
 * 而再次放入数据将会覆盖旧数据，所以不需要清除没有消失的旧数据 
 */ 
Status ClearStack(SqStack &S){
	if(S.base)
		S.top=S.base;
	return OK;
}

/*
 * 销毁栈
 * free掉S.base指向的栈底指针（数组首地址）
 * 设置栈大小为0，S.top和S.base指向null，回收指针 
 */ 
Status DestroyStack(SqStack &S){
	if(S.base){
		free(S.base);
		S.stacksize=0;
		S.base=S.top=NULL;
	}
	return OK;
}

//     顺序栈进栈
// (1) 判断是否满栈，若满则出错
// (2) 元素e压入栈顶
// (3) 栈顶指针加1 

/*
 * 压入栈
 * 首先判断大小，然后压栈，先入数据，再top++ 
 */ 
Status Push(SqStack &S,Book e){
	if(S.top-S.base==S.stacksize){ // 栈满 
		return ERROR;
	}
	*S.top++=e;
	return OK;
}

/*
 * 超级压入栈
 * 首先判断大小，然后压栈，先入数据，再top++ 
 * 压入栈的父类，省去了Book e的声明 
 */ 
Status SuperPush(SqStack &S,const char *no,const char *name,float price){
	Book elem;
	strcpy(elem.no,no);
	strcpy(elem.name,name);
	elem.price=price;
	Push(S,elem);
}

/*
 * 出栈 
 * 判断栈是不是空 
 * 先--top，在出数据 
 * 
 */ 
Status Pop(SqStack &S,Book &e){
	if(S.top==S.base){ // 栈空 
		return ERROR;
	}
	e=*--S.top;
	return OK;
}

// (1) 判断是否空栈，若空则返回错误
// (2) 否则通过栈顶指针获取栈顶元素
Status GetTop(SqStack S,Book &e){
	if(S.top==S.base) return ERROR;
	e=*(S.top-1);
	return OK;
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

/*
 *  遍历栈 
 */ 
void TraverseList(SqStack sqStack){
	int i;
	int length=StackLength(sqStack);
	for(i=length-1;i>=0;i--){
		printf("%s %s %f\n",sqStack.base[i].name,sqStack.base[i].no,sqStack.base[i].price);
	}
}

void unit(){
	SqStack sqStack;
	JudgeResponseCode(InitStack(sqStack)); // 初始化成功 
	
	if(StackEmpty(sqStack)){
		printf("的确为空\n");
	}
	
	JudgeResponseCode(SuperPush(sqStack,"123123","JAVA",30.5));
	JudgeResponseCode(SuperPush(sqStack,"456456","C++",40.5));
	JudgeResponseCode(SuperPush(sqStack,"789789","易语言",50.5));
	TraverseList(sqStack);
	
	Book b;	
	JudgeResponseCode(Pop(sqStack,b));
	
	printf("%s %s %.0f\n",b.name,b.no,b.price);
	
	printf("%d\n",StackLength(sqStack));
	
//	ClearStack(sqStack);
//	printf("%d\n",StackLength(sqStack));
	
	DestroyStack(sqStack);
	TraverseList(sqStack);
}

//int main(){
//	unit();
//}
