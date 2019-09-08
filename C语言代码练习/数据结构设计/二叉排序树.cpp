#include<iostream>
using namespace std;
#define ENGFLAG -1

typedef struct ElemType{
	int key;
}ElemType;

typedef struct BSTNode{
	ElemType data;             // 结点数据域 
	BSTNode *lchild,*rchild;   // 左右孩子指针 
}BSTNode,*BSTree;
void InOrderTraverse(BSTree&);
// 二叉排序树递归查找 
BSTree SearchBST(BSTree T,int key) {
	if((!T)||key==T->data.key)
		return T;
	else if(key<T->data.key)
		return SearchBST(T->lchild,key);
	else
		return SearchBST(T->rchild,key);
}

// 二叉排序树的插入 
void InsertBST(BSTree &T,ElemType e){
	// 当二叉树T中不存在关键字等于e.key的数据元素，则插入该元素 
	if(!T){		// 找到插入位置，递归结束 
		BSTree S=new BSTNode;
		S->data=e;
		S->lchild=S->rchild=NULL;
		T=S; 
		// 递归的时候，只改变当前位置的指针 
		// 递归回来的时候头指针的位置是不变的 
	}else if(e.key<T->data.key)
		InsertBST(T->lchild,e);
	else if(e.key>T->data.key)
		InsertBST(T->rchild,e);
} // InsertBST

void CreateBST(BSTree &T){
	// 依次读入一个关键字为key的结点，将此结点插入二叉排序树T中
	T=NULL;
	ElemType e;
	cin>>e.key;
	while(e.key!=ENGFLAG){//ENDFLAG为自定义常量，作为输入结束标志
		InsertBST(T,e);//将此结点插入二叉排序树T中
		cin>>e.key;
	}
}

void DeleteBST(BSTree &T,int key){
 	// 从二叉排序树T中删除关键字等于key的结点
	BSTree p=T,f=NULL,q,s;
	/*------------下面的while循环从根开始查找关键字等于key的结点*p-------------*/
	while(p){
		if(p->data.key==key)
			break;
		f=p;
		if(p->data.key>key)
			p=p->lchild;
		else
			p=p->rchild;
	}
	if(!p)
		return;
	// 考虑三种情况实现p所指子树内部的处理：*p左右树均不空、无右子树、无左子树 
	if((p->lchild)&&(p->rchild)){
		q=p;
		s=p->lchild;
		while(s->rchild){
			q=s;
			s=s->rchild;
		}
		p->data=s->data;
		if(q!=p){
			q->rchild=s->lchild;
		}else{
			q->lchild=s->lchild;
		}
		delete s;
	}else{
		if(!p->rchild){
			q=p;
			p=p->lchild;
		}else if(!p->lchild){
			q=p;
			p=p->rchild;
		}
		if(!f)
			T=p;
		else if(q==f->lchild)
			f->lchild=p;
		else 
			f->rchild=p;
		delete q;
	}
}

void InOrderTraverse(BSTree &T){
	if(T){
		InOrderTraverse(T->lchild);
		cout<<T->data.key<<" ";
		InOrderTraverse(T->rchild);
	}
} 

// 10 20 30 40 50 25 23 35 80 90 85 88 -1
// 50 30 20 40 10 25 23 35 80 90 85 88 -1


int main(){
	BSTree T;
	cout<<"请输入若干字符，用回车区分，以-1结束输入"<<endl;
	CreateBST(T);
	cout<<"当前有序二叉树中序遍历结果为"<<endl;
	InOrderTraverse(T);
	int key;//待查找或待删除内容
	cout<<"请输入待查找字符"<<endl;
	cin>>key;
	BSTree result=SearchBST(T,key);
	if(result)
	{cout<<"找到字符"<<key<<endl;}
	else
	{cout<<"未找到"<<key<<endl;}
	cout<<"请输入待删除的字符"<<endl;
	cin>>key;
	DeleteBST(T,key);
	cout<<"当前有序二叉树中序遍历结果为"<<endl;
	InOrderTraverse(T);
}


