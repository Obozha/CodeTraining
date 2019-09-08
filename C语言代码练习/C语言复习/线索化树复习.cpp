#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef char TElemType;
//二叉链表结构
typedef struct BiTNode {
	TElemType data;       //数据域,存放结点值
	struct BiTNode *lchild,*rchild;      //左右孩子指针
} BiTNode,*BiTree; // 二叉链表

//二叉线索链表结构
typedef struct BiThrNode {
	TElemType data;        //数据域，存放结点值
	struct BiThrNode *lchild,*rchild;          //左右孩子指针
	int LTag,RTag;    //左右标志，0表示指针，1表示线索
} BiThrNode,*BiThrTree;  //线索链表结构

//中序线索化二叉树时的pre指针
BiThrNode *pre=NULL;

//输入二叉树的先序遍历序列（空树用字符","表示），创建二叉链表
void creatbitree(BiTree &T) {
	char ch;
	ch=getchar();
	if(ch==',')     //空树时的情况
		T=NULL;
	else {    //二叉树非空，递归建其对应的二叉链表
		T=(BiTNode *)malloc(sizeof(BiTNode));   //申请结点空间
		if(!T)  exit(-1);   //存储空间申请失败，退出程序
		T->data =ch;        //为结点赋值
		creatbitree(T->lchild);   //递归创建T的左子树的二叉链表
		creatbitree(T->rchild);   //递归创建T的右子树的二叉链表
	}
}

//中序遍历二叉树T
void inorder(BiTree T) {
	if(T) {
		//请根据注释内容，在下面补充代码
		//中序遍历T的左子树
		inorder(T->lchild);
		//访问结点T
		cout<<T->data;
		//中序遍历T的右子树
		inorder(T->rchild);
	}
}

//先序遍历二叉树T
void preorder(BiTree T) {
	if(T) {
		//请根据注释内容，在下面补充代码
		//访问结点T
		cout<<T->data;
		//先序遍历T的左子树
		preorder(T->lchild);
		//先序遍历T的右子树
		preorder(T->rchild);
	}
}

//后序遍历二叉树T
void postorder(BiTree T) {
	if(T) {
		//请根据注释内容，在下面补充代码
		//后序遍历T的左子树
		postorder(T->lchild);
		//后序遍历T的右子树
		postorder(T->rchild);
		//访问结点T
		cout<<T->data;
	}
}

//根据输入的先序序列（空树用字符","表示），创建二叉线索链表
void creatbitree1(BiThrTree &T) {
	char ch;
	ch=getchar();
	if(ch==',')       //空树时的情况
		T=NULL;
	else {     //树非空时
		T=(BiThrNode *)malloc(sizeof(BiThrNode));    //申请结点空间
		if(!T)  exit(-1);   //存储空间申请失败，退出程序
		T->data =ch;        //为结点赋值
		creatbitree1(T->lchild);    //递归创建T的左子树的二叉链表
		creatbitree1(T->rchild);    //递归创建T的右子树的二叉链表
	}
}


//中序线索化二叉树T
void inthread(BiThrTree &T) {
	if(T) {
		inthread(T->lchild);   //中序线索化T的左子树
		if(pre!=NULL) {   //处理pre（中序遍历时刚访问的结点）结点的rtag与rchild，T为当前正在访问的结点
			if(pre->rchild ==NULL) { //若pre的右指针域rchild为空，则将其改造为线索
				//请根据注释补充此处代码
				pre->RTag=1;   // 给pre加上右线索 
				pre->rchild=T; // pre有孩子指向p（后继） 
			} else       //若pre的右指针域rchild非空，设置其rtag值
				pre->RTag =0;
		}
		if(T->lchild ==NULL) { //处理当前正在访问的结点(T)的ltag与lchild
			//请根据注释补充此处代码
			T->RTag=1;	// 给pre加上右线索 
			T->lchild=pre;// pre的右孩子指针指向p（后继） 
		} else      //若T的左指针域lchild非空，设置其ltag值
			T->LTag =0;
		pre=T;     //将当前结点变成刚刚访问过的结点
		inthread(T->rchild );   //中序线索化T的右子树
	}
}

//在中序线索链表中（以p为根）查找遍历的第一个结点
BiThrTree first(BiThrTree p) {
	if(p) {
		while(p->LTag ==0) {  //中序线索链表中访问的第一个结点必为最左下的结点，寻找最左下的结点
			p=p->lchild;
		}
		return p;    //返回找到的第一个结点
	} else 
		return NULL;
}

//在中序线索链表中查找结点p的中序后继,函数返回找到的p的中序后继
BiThrTree next(BiThrTree p) {
	if(p) {
		if(p->RTag ==1) { //若p没有右孩子，其中序后继为？
			//请根据注释补充此处代码
			return p->rchild;
		} else {  //若p有右孩子，其中序后继为？
			//请根据注释补充此处代码
			first(p->rchild);
		}
	}
}

//遍历以T为根的中序线索二叉树
void intravers(BiThrTree T) {
	BiThrNode *s;
	if(T) {
		//先通过first函数找遍历时的第一个结点s
		//请根据注释补充此处代码
		s=first(T);
		while(s) {
			printf("%5c",s->data );    //输出结点值
			//找s的后继结点
			//请根据注释补充此处代码
			s=next(s);
		}
	}
}

//在中序线索链表T中查找值为ch的结点
void searchthrtree(BiThrTree T,char ch) {
	BiThrNode *s;
	if(T) {
		s=first(T);
		while(s&&s->data !=ch) {
			s=next(s);
		}
		if(s==NULL)     //因中序线索链表中最后一个结点的rchild为NULL，s=NULL,意味着对中序线索链表查找完毕
			printf("没有该结点！\n");
		else
			printf("查找成功！\n");
	}
}

bool flag;
void searchtree(BiTree T,char ch) {
	if(T) { // 若二叉树非空
		if(ch==T->data) {
			flag=true;
		}
		searchtree(T->lchild,ch); // 前序遍历左子树
		searchtree(T->rchild,ch); // 前序序遍历右子树
	}
}

// ABC,,DE,G,,F,,,
int main() {
	BiTree T;       //T为本程序中要操作的二叉链表
	BiThrTree T1;   //T1为本程序中要操作的二叉线索链表
	char ch,ch1;    //ch和ch1分别表示在二叉树和线索二叉树中要查询的结点
	bool t;
	printf("请输入要创建的二叉树，按先序序列输入，空树用字符','代替\n");
	creatbitree(T);  //根据输入的二叉树先序序列，创建二叉链表T
	printf("\n中序遍历结果为：");
	inorder(T);      //输出二叉树T的中序遍历序列
	printf("\n先序遍历结果为：");
	preorder(T);     //输出二叉树T的先序遍历序列
	printf("\n后序遍历结果为：");
	postorder(T);    //输出二叉树T的后序遍历序列
	printf("\n请输入在二叉树中要查找的结点：");
	rewind(stdin);   //清空输入缓冲区
	scanf("%c",&ch1);
	searchtree(T,ch1);   //在二叉树T中查找值为ch1的结点
	if(flag) printf("在二叉树中查找成功\n");
	else printf("在二叉树中查找不成功\n");

	//以下操作以中序线索二叉树为例，完成中序线索二叉树的建立、遍历及查找操作
	printf("请输入要创建的中序线索二叉树，按先序序列输入，空树用字符','代替\n");
	rewind(stdin);
	creatbitree1(T1);  //根据输入的二叉树先序序列，创建二叉链表T1
	inthread(T1);      //对T1进行中序线索化（创建二叉线索链表）
	printf("中序线索二叉树的遍历结果为：");
	intravers(T1);     //对中序线索链表T1进行遍历，并输出遍历序列
	printf("\n请输入在中序线索二叉树中要查找的结点：\n");
	rewind(stdin);
	scanf("%c",&ch);
	searchthrtree(T1,ch);  //在线索二叉树T1中查找值为ch的结点
}
