#include<iostream>
using namespace std;
#define ENGFLAG -1

typedef struct ElemType{
	int key;
}ElemType;

typedef struct BSTNode{
	ElemType data;             // ��������� 
	BSTNode *lchild,*rchild;   // ���Һ���ָ�� 
}BSTNode,*BSTree;
void InOrderTraverse(BSTree&);
// �����������ݹ���� 
BSTree SearchBST(BSTree T,int key) {
	if((!T)||key==T->data.key)
		return T;
	else if(key<T->data.key)
		return SearchBST(T->lchild,key);
	else
		return SearchBST(T->rchild,key);
}

// �����������Ĳ��� 
void InsertBST(BSTree &T,ElemType e){
	// ��������T�в����ڹؼ��ֵ���e.key������Ԫ�أ�������Ԫ�� 
	if(!T){		// �ҵ�����λ�ã��ݹ���� 
		BSTree S=new BSTNode;
		S->data=e;
		S->lchild=S->rchild=NULL;
		T=S; 
		// �ݹ��ʱ��ֻ�ı䵱ǰλ�õ�ָ�� 
		// �ݹ������ʱ��ͷָ���λ���ǲ���� 
	}else if(e.key<T->data.key)
		InsertBST(T->lchild,e);
	else if(e.key>T->data.key)
		InsertBST(T->rchild,e);
} // InsertBST

void CreateBST(BSTree &T){
	// ���ζ���һ���ؼ���Ϊkey�Ľ�㣬���˽��������������T��
	T=NULL;
	ElemType e;
	cin>>e.key;
	while(e.key!=ENGFLAG){//ENDFLAGΪ�Զ��峣������Ϊ���������־
		InsertBST(T,e);//���˽��������������T��
		cin>>e.key;
	}
}

void DeleteBST(BSTree &T,int key){
 	// �Ӷ���������T��ɾ���ؼ��ֵ���key�Ľ��
	BSTree p=T,f=NULL,q,s;
	/*------------�����whileѭ���Ӹ���ʼ���ҹؼ��ֵ���key�Ľ��*p-------------*/
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
	// �����������ʵ��p��ָ�����ڲ��Ĵ���*p�����������ա������������������� 
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
	cout<<"�����������ַ����ûس����֣���-1��������"<<endl;
	CreateBST(T);
	cout<<"��ǰ�������������������Ϊ"<<endl;
	InOrderTraverse(T);
	int key;//�����һ��ɾ������
	cout<<"������������ַ�"<<endl;
	cin>>key;
	BSTree result=SearchBST(T,key);
	if(result)
	{cout<<"�ҵ��ַ�"<<key<<endl;}
	else
	{cout<<"δ�ҵ�"<<key<<endl;}
	cout<<"�������ɾ�����ַ�"<<endl;
	cin>>key;
	DeleteBST(T,key);
	cout<<"��ǰ�������������������Ϊ"<<endl;
	InOrderTraverse(T);
}


