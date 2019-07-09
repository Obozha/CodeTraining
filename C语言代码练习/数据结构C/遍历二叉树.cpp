#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

// - - - - 二叉树的二叉链表存储表示 - - - -
typedef char TElemType;

typedef struct BiTNode {
	TElemType data;					// 结点数据域
	struct BiTNode *lchild,*rchild; // 左右孩子指针
} BiTNode,*BiTree;

typedef struct {
	BiTree *base;  // 栈底指针
	BiTree *top;	// 栈顶指针
	int stacksize;	// 栈可用的最大容量
} SqStack;

int InitStack(SqStack &S) {
	// 创建一个空栈
	S.base=(BiTree*)malloc(sizeof(BiTree)*MAXSIZE);
	// BiTree 是一个指针，要建立一个存放指针的数组
	// (指针的指针)malloc(sizeof(指针)*MAXSIZE);
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
	// 删除S的栈顶元素，用e返回其值
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

/* ①扫描字符序列，读入字符ch
 * ②如果ch是一个"#"字符，则表明该二叉树为空树，即T为NULL；否则执行以下操作
 * 		# 申请一个结点空间T
 *  	# 将ch赋给T->data
 *		# 递归创建T的左子树
 *		# 递归创建T的右子树
 */
void CreateBiTree(BiTree &T) {
	// 按先后次序输入二叉树中结点的值（一个字符），创建二叉链表表示二叉树T
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
		T=NULL;
	else {
		T=(BiTree)malloc(sizeof(BiTNode)); // 生成根节点
		T->data=ch;						   // 根结点数据域置为ch
		CreateBiTree(T->lchild);		   // 递归创建左子树
		CreateBiTree(T->rchild);		   // 递归创建右子树
	}
}


bool flag;
void SearchTree(BiTree T,char ch,BiTree &p) {
	if(T) { // 若二叉树非空
		if(ch==T->data) {
			flag=true;
			p=T;
		}
		SearchTree(T->lchild,ch,p); // 前序遍历左子树
		SearchTree(T->rchild,ch,p); // 前序序遍历右子树
	}
}

void InOrderTraverse(BiTree T) {
	// 中序遍历二叉树T的递归算法
	if(T) { // 若二叉树非空
		InOrderTraverse(T->lchild); // 中序遍历左子树
		printf("%c ",T->data);		// 访问根结点
		InOrderTraverse(T->rchild); // 中序遍历右子树
	}
}

void PreOrderTraverse(BiTree T) {
	// 前序遍历二叉树T的递归算法
	if(T) { // 若二叉树非空
		printf("%c ",T->data);		// 访问根结点
		PreOrderTraverse(T->lchild); // 前序遍历左子树
		PreOrderTraverse(T->rchild); // 前序序遍历右子树
	}
}

void PostOrderTraverse(BiTree T) {
	// 后续遍历二叉树T的递归算法
	if(T) { // 若二叉树非空
		PostOrderTraverse(T->lchild); // 后续遍历左子树
		PostOrderTraverse(T->rchild); // 后续遍历右子树
		printf("%c ",T->data); // 访问根结点
	}
}

/*
 * 如果是空树，递归结束，深度为0，否则执行以下操作：
 * 		# 递归计算左子树的深度记为m
 *		# 递归计算右子树的深度记为n
 *		# 如果m大于n，二叉树的深度为m+1，否则为n+1
 */
int Depth(BiTree T) {
	// 计算二叉树的T的深度
	if(T==NULL)
		return 0;
	else {
		int m=Depth(T->lchild);
		int n=Depth(T->rchild);
		return (m>n)?(m+1):(n+1);
	}
}

int NodeCount(BiTree T) {
	// 统计二叉树T中结点的个数
	if(T==NULL)
		return 0; // 如果是空树，则结点个数为0，递归结束
	else
		return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}

int LeafCount(BiTree T) {
	int m,n; // m,n分别表示左右子树中叶子的个数
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
	if(T) { // 若二叉树非空
		if( (T->lchild!=NULL&&T->rchild==NULL)||(T->lchild==NULL&&T->rchild!=NULL)  ){
			Count1++;
		}
		NodeCount1(T->lchild); // 后续遍历左子树
		NodeCount1(T->rchild); // 后续遍历右子树
	}
}

int Count2=0;
void NodeCount2(BiTree T) {
	if(T) { // 若二叉树非空
		if( (T->lchild!=NULL&&T->rchild==NULL)||(T->lchild==NULL&&T->rchild!=NULL)  ){
			Count2++;
		}
		NodeCount2(T->lchild); // 后续遍历左子树
		NodeCount2(T->rchild); // 后续遍历右子树
	}
}

void InOrderTraverse_rc(BiTree T) {
	// 中序遍历二叉树T的非递归算法
	SqStack S;
	InitStack(S);
	BiTree p=T,q=(BiTree)malloc(sizeof(BiTNode));
	while(p||!StackEmpty(S)) {
		if(p) { // p非空
			Push(S,p);
			p=p->lchild;
		} else {
			Pop(S,q); // 退栈
			printf("%c ",q->data); // 访问根结点
			p=q->rchild;  // 遍历右子树
		}
	}
}

// 如果是空树，递归结束，否则执行以下操作
//  # 申请一个新结点空间，复制根结点；
//  # 递归复制左子树。
//  # 递归复制右子树。
void Copy(BiTree T,BiTree &NewT) {
	// 复制一颗和T完全相同的二叉树
	if(T==NULL) {							// 如果是空树，递归结束
		NewT=NULL;
		return;
	} else {
		NewT=(BiTree)malloc(sizeof(BiTNode));
//		printf("%c %c",NewT->data,T->data);

		NewT->data=T->data;  			// 复制根结点
		Copy(T->lchild,NewT->lchild);	// 递归复制左子树
		Copy(T->rchild,NewT->rchild);	// 递归复制右子树
	}									// else
}

// ABC##DE#G##F### 树的输入数据（通过递归）
int main() {
	BiTree bt,newBt,p;
	CreateBiTree(bt);
	printf("前序遍历的结果是：\n");
	PreOrderTraverse(bt);
	printf("\n");
	printf("中序遍历的结果是：\n");
	InOrderTraverse_rc(bt);
	printf("\n");
	printf("后序遍历的结果是：\n");
	PostOrderTraverse(bt);
	printf("\n");
	printf("树的深度为：%d\n",Depth(bt));
	printf("树的结点个数为：%d\n",NodeCount(bt));
	// --------------------
	Copy(bt,newBt);
	InOrderTraverse_rc(newBt);
	SearchTree(bt,'D',p);
	//printf("%d",flag);
	if(flag) {
		printf("\n查找结点成功 返回值：%c",p->data);
	} else {
		printf("\n查找结点失败");
	}
	printf("\n一共有%d叶结点\n",LeafCount(bt));
	NodeCount2(bt);
	NodeCount1(bt);
	printf("二叉树T中度为1的结点的数量:%d\n",Count1);
	printf("二叉树T中度为2的结点的数量:%d\n",Count2);
}
