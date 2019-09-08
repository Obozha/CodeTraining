#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

// - - - - �������Ķ�������洢��ʾ - - - -
typedef char TElemType;

typedef struct BiTNode {
	TElemType data;					// ���������
	struct BiTNode *lchild,*rchild; // ���Һ���ָ��
} BiTNode,*BiTree;

typedef struct {
	BiTree *base;  // ջ��ָ��
	BiTree *top;	// ջ��ָ��
	int stacksize;	// ջ���õ��������
} SqStack;

int InitStack(SqStack &S) {
	// ����һ����ջ
	S.base=(BiTree*)malloc(sizeof(BiTree)*MAXSIZE);
	// BiTree ��һ��ָ�룬Ҫ����һ�����ָ�������
	// (ָ���ָ��)malloc(sizeof(ָ��)*MAXSIZE);
	if(!S.base)
		return -1;
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return 1;
}

int Push(SqStack &S,BiTree bt) {
	if(S.top-S.base==S.stacksize)
		return 0;
	*S.top++=bt;
	return 1;
}

int Pop(SqStack &S,BiTree &bt) {
	// ɾ��S��ջ��Ԫ�أ���e������ֵ
	if(S.top==S.base)
		return 0;
	bt=*--S.top;
	return 1;
}

int StackEmpty(SqStack S) {
	if(S.top==S.base)
		return 1;
	return 0;
}

/* ��ɨ���ַ����У������ַ�ch
 * �����ch��һ��"#"�ַ���������ö�����Ϊ��������TΪNULL������ִ�����²���
 * 		# ����һ�����ռ�T
 *  	# ��ch����T->data
 *		# �ݹ鴴��T��������
 *		# �ݹ鴴��T��������
 */
void CreateBiTree(BiTree &T) {
	// ���Ⱥ��������������н���ֵ��һ���ַ������������������ʾ������T
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
		T=NULL;
	else {
		T=(BiTree)malloc(sizeof(BiTNode)); // ���ɸ��ڵ�
		T->data=ch;						   // �������������Ϊch
		CreateBiTree(T->lchild);		   // �ݹ鴴��������
		CreateBiTree(T->rchild);		   // �ݹ鴴��������
	}
}


bool flag;
void SearchTree(BiTree T,char ch,BiTree &p) {
	if(T) { // ���������ǿ�
		if(ch==T->data) {
			flag=true;
			p=T;
		}
		SearchTree(T->lchild,ch,p); // ǰ�����������
		SearchTree(T->rchild,ch,p); // ǰ�������������
	}
}

void InOrderTraverse(BiTree T) {
	// �������������T�ĵݹ��㷨
	if(T) { // ���������ǿ�
		InOrderTraverse(T->lchild); // �������������
		printf("%c ",T->data);		// ���ʸ����
		InOrderTraverse(T->rchild); // �������������
	}
}

void PreOrderTraverse(BiTree T) {
	// ǰ�����������T�ĵݹ��㷨
	if(T) { // ���������ǿ�
		printf("%c ",T->data);		// ���ʸ����
		PreOrderTraverse(T->lchild); // ǰ�����������
		PreOrderTraverse(T->rchild); // ǰ�������������
	}
}

void PostOrderTraverse(BiTree T) {
	// ��������������T�ĵݹ��㷨
	if(T) { // ���������ǿ�
		PostOrderTraverse(T->lchild); // ��������������
		PostOrderTraverse(T->rchild); // ��������������
		printf("%c ",T->data); // ���ʸ����
	}
}

/*
 * ����ǿ������ݹ���������Ϊ0������ִ�����²�����
 * 		# �ݹ��������������ȼ�Ϊm
 *		# �ݹ��������������ȼ�Ϊn
 *		# ���m����n�������������Ϊm+1������Ϊn+1
 */
int Depth(BiTree T) {
	// �����������T�����
	if(T==NULL)
		return 0;
	else {
		int m=Depth(T->lchild);
		int n=Depth(T->rchild);
		return (m>n)?(m+1):(n+1);
	}
}

int NodeCount(BiTree T) {
	// ͳ�ƶ�����T�н��ĸ���
	if(T==NULL)
		return 0; // ����ǿ������������Ϊ0���ݹ����
	else
		return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}

int LeafCount(BiTree T) {
	int m,n; // m,n�ֱ��ʾ����������Ҷ�ӵĸ���
	if(T==NULL)
		return 0;
	else if(T->lchild==NULL&&T->rchild==NULL)
		return 1;
	else {
		m=LeafCount(T->lchild);
		n=LeafCount(T->rchild);
		return m+n;
	}
}

int Count1=0;
void NodeCount1(BiTree T) {
	if(T) { // ���������ǿ�
		if( (T->lchild!=NULL&&T->rchild==NULL)||(T->lchild==NULL&&T->rchild!=NULL)  ){
			Count1++;
		}
		NodeCount1(T->lchild); // ��������������
		NodeCount1(T->rchild); // ��������������
	}
}

int Count2=0;
void NodeCount2(BiTree T) {
	if(T) { // ���������ǿ�
		if( (T->lchild!=NULL&&T->rchild==NULL)||(T->lchild==NULL&&T->rchild!=NULL)  ){
			Count2++;
		}
		NodeCount2(T->lchild); // ��������������
		NodeCount2(T->rchild); // ��������������
	}
}

void InOrderTraverse_rc(BiTree T) {
	// �������������T�ķǵݹ��㷨
	SqStack S;
	InitStack(S);
	BiTree p=T,q=(BiTree)malloc(sizeof(BiTNode));
	while(p||!StackEmpty(S)) {
		if(p) { // p�ǿ�
			Push(S,p);
			p=p->lchild;
		} else {
			Pop(S,q); // ��ջ
			printf("%c ",q->data); // ���ʸ����
			p=q->rchild;  // ����������
		}
	}
}

// ����ǿ������ݹ����������ִ�����²���
//  # ����һ���½��ռ䣬���Ƹ���㣻
//  # �ݹ鸴����������
//  # �ݹ鸴����������
void Copy(BiTree T,BiTree &NewT) {
	// ����һ�ź�T��ȫ��ͬ�Ķ�����
	if(T==NULL) {							// ����ǿ������ݹ����
		NewT=NULL;
		return;
	} else {
		NewT=(BiTree)malloc(sizeof(BiTNode));
//		printf("%c %c",NewT->data,T->data);

		NewT->data=T->data;  			// ���Ƹ����
		Copy(T->lchild,NewT->lchild);	// �ݹ鸴��������
		Copy(T->rchild,NewT->rchild);	// �ݹ鸴��������
	}									// else
}

// ABC##DE#G##F### �����������ݣ�ͨ���ݹ飩
int main() {
	BiTree bt,newBt,p;
	CreateBiTree(bt);
	printf("ǰ������Ľ���ǣ�\n");
	PreOrderTraverse(bt);
	printf("\n");
	printf("��������Ľ���ǣ�\n");
	InOrderTraverse_rc(bt);
	printf("\n");
	printf("��������Ľ���ǣ�\n");
	PostOrderTraverse(bt);
	printf("\n");
	printf("�������Ϊ��%d\n",Depth(bt));
	printf("���Ľ�����Ϊ��%d\n",NodeCount(bt));
	// --------------------
	Copy(bt,newBt);
	InOrderTraverse_rc(newBt);
	SearchTree(bt,'D',p);
	//printf("%d",flag);
	if(flag) {
		printf("\n���ҽ��ɹ� ����ֵ��%c",p->data);
	} else {
		printf("\n���ҽ��ʧ��");
	}
	printf("\nһ����%dҶ���\n",LeafCount(bt));
	NodeCount2(bt);
	NodeCount1(bt);
	printf("������T�ж�Ϊ1�Ľ�������:%d\n",Count1);
	printf("������T�ж�Ϊ2�Ľ�������:%d\n",Count2);
}
