#include<stdio.h>
#include<stdlib.h>

// - - - - 二叉树的二叉线索存储表示 - - - - 
typedef char TElemType;
typedef struct BiThrNode{
	TElemType data;
	struct BiThrNode *lchild,*rchild; // 左右孩子指针
	int LTag,RTag;					  // 左右标志 
}BiThrNode,*BiThrTree; 

BiThrTree pre;
void InThreading(BiThrTree p){
	// pre是全局变量，初始化时其右孩子指针为空，便于在树的最左点开始建线索
	if(p){
		InThreading(p->lchild); // 左子树递归线索化
		if(!p->lchild){ 		// p的左孩子为空 
			p->LTag=1;
			p->lchild=pre;		// p的左孩子指向前驱 
		}else{
			p->LTag=0;
		} 
		if(!pre->rchild){
			pre->RTag=1;		// 给pre加上右线索 
			pre->rchild=p;		// pre的右孩子指针指向p（后继） 
		}else{
			pre->RTag=0;
		}
		pre=p;					// 保持pre指向p的前驱 
		InThreading(p->rchild); // 右子树递归线索化 
	} 
}

void InOrderThreading(BiThrTree &Thrt,BiThrTree T){
	// 中序遍历二叉树T，并将其中序线索化，Thrt指向头结点
	Thrt=(BiThrTree)malloc(sizeof(BiThrNode)); // 建立头结点 
	Thrt->LTag=0;							   // 头结点有左孩子，若树非空，则其左孩子为树根 
	Thrt->RTag=1;							   // 头结点的右孩子指针为右线索
	Thrt->rchild=Thrt;						   // 初始化时右指针指向自己
	if(!T)
		Thrt->lchild=T;
	else{
		Thrt->lchild=T;
		pre=Thrt;
		InThreading(T);
		pre->rchild=Thrt;
		pre->RTag=1;
		Thrt->rchild=pre; // 头结点的右线索	
	}
} 

/*
 * ①指针p指向根节点。
 * ②p为非空树或遍历结束时，执行以下操作
 * 	* 沿左孩子向下，到达最左下结点*p,它是中序的第一个结点
 *	* 访问*p
 *	* 沿右线索反复查找当前结点*p的后继结点并访问后继结点，直至右线索为0或者遍历结束 
 *	* 转向p的右子树 
 */
void InOrderTraverse_Thr(BiThrTree T){
	 // T指向头结点，头结点的左链lchild指向根节点
	 // 中序遍历二叉树线索树T的非递归算法，对每个数据元素直接输出
	BiThrTree p=T->lchild;
	while(p!=T){
		while(p->LTag==0)
			p=p->lchild;
		printf("%c ",p->data);
		while(p->RTag==1&&p->rchild!=T){
			p=p->rchild;
			printf("%c ",p->data); // 沿着右线索访问后继结点 
		}
		p=p->rchild;			   // 转向p的右子树 
	}
}

void CreateBiTree(BiThrTree &T){
	// 按照次序输入二叉树结点的值（一个字符），创建二叉链表表示的二叉树T 
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
		T=NULL; // 递归结束，建空树
	else{
		T=(BiThrTree)malloc(sizeof(BiThrNode));
		T->data=ch;
		CreateBiTree(T->lchild); // 递归创建左子树
		CreateBiTree(T->rchild); // 递归创建右子树 
	} 							 // else 
}
// ABC##DE#G##F### 树的输入数据（通过递归）
int main(){
	BiThrTree bt,thrt;
	pre=(BiThrTree)malloc(sizeof(BiThrNode));
	CreateBiTree(bt);
	InOrderThreading(thrt,bt);
	InOrderTraverse_Thr(thrt);
}
