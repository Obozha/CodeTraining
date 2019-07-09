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

// ˳��ջ��ʼ��
// ����һ����ջ
// ���裺
// (1) ����ռ䲢���ռ��Ƿ����ʧ��
//     ��ʧ���򷵻ش���
// (2) ����ջ�׺�ջ��ָ��
// S.top=S.base;
// (3) ����ջ��С 

/*
 * ����һ����ջ 
 */
Status InitStack(SqStack &S){
	S.base=(Book*)malloc(MAXSIZE*sizeof(Book)); // ��ʼ��ջ������� 
	if(!S.base)
		return OVERFLOW;
	S.top=S.base;								// ջ�׺�ջ��ָ��ͬһ��λ�� 
	S.stacksize=MAXSIZE;						// ջ���ô�С 
	return OK;
}

/*
 * ջ�Ƿ�Ϊ��
 * 1���ǿ� 
 * 0���Ƿǿ� 
 */ 
int StackEmpty(SqStack S){
	if(S.top==S.base)
		return 1;
	else
		return 0;
}

/*
 * ջ�ĳ���
 * ջ��ָ���ȥջ��ָ��
 * ջ��ָ���ܻᳬ�����鵱ǰ���ݵ�ָ�룬Ϊ���Ǽ�ȥ����Ϊ����ֵ
 * ָ��ļ���Ҳ�� p+0 p+1 p+2 ��0��ʼ�� 
 */ 
int StackLength(SqStack S){
	return S.top-S.base;
}

/*
 * ���ջ������Ҫ����Ԫ�� 
 * ע������ֻ�ǽ�ջ����ָ��ָ����ջ�ף�ʵ�����ݲ�û����ʧ
 * ���ٴη������ݽ��Ḳ�Ǿ����ݣ����Բ���Ҫ���û����ʧ�ľ����� 
 */ 
Status ClearStack(SqStack &S){
	if(S.base)
		S.top=S.base;
	return OK;
}

/*
 * ����ջ
 * free��S.baseָ���ջ��ָ�루�����׵�ַ��
 * ����ջ��СΪ0��S.top��S.baseָ��null������ָ�� 
 */ 
Status DestroyStack(SqStack &S){
	if(S.base){
		free(S.base);
		S.stacksize=0;
		S.base=S.top=NULL;
	}
	return OK;
}

//     ˳��ջ��ջ
// (1) �ж��Ƿ���ջ�����������
// (2) Ԫ��eѹ��ջ��
// (3) ջ��ָ���1 

/*
 * ѹ��ջ
 * �����жϴ�С��Ȼ��ѹջ���������ݣ���top++ 
 */ 
Status Push(SqStack &S,Book e){
	if(S.top-S.base==S.stacksize){ // ջ�� 
		return ERROR;
	}
	*S.top++=e;
	return OK;
}

/*
 * ����ѹ��ջ
 * �����жϴ�С��Ȼ��ѹջ���������ݣ���top++ 
 * ѹ��ջ�ĸ��࣬ʡȥ��Book e������ 
 */ 
Status SuperPush(SqStack &S,const char *no,const char *name,float price){
	Book elem;
	strcpy(elem.no,no);
	strcpy(elem.name,name);
	elem.price=price;
	Push(S,elem);
}

/*
 * ��ջ 
 * �ж�ջ�ǲ��ǿ� 
 * ��--top���ڳ����� 
 * 
 */ 
Status Pop(SqStack &S,Book &e){
	if(S.top==S.base){ // ջ�� 
		return ERROR;
	}
	e=*--S.top;
	return OK;
}

// (1) �ж��Ƿ��ջ�������򷵻ش���
// (2) ����ͨ��ջ��ָ���ȡջ��Ԫ��
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
 *  ����ջ 
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
	JudgeResponseCode(InitStack(sqStack)); // ��ʼ���ɹ� 
	
	if(StackEmpty(sqStack)){
		printf("��ȷΪ��\n");
	}
	
	JudgeResponseCode(SuperPush(sqStack,"123123","JAVA",30.5));
	JudgeResponseCode(SuperPush(sqStack,"456456","C++",40.5));
	JudgeResponseCode(SuperPush(sqStack,"789789","������",50.5));
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
