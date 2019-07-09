#include<stdio.h>
#include<stdlib.h>

// - - - - �������Ķ��������洢��ʾ - - - - 
typedef char TElemType;
typedef struct BiThrNode{
	TElemType data;
	struct BiThrNode *lchild,*rchild; // ���Һ���ָ��
	int LTag,RTag;					  // ���ұ�־ 
}BiThrNode,*BiThrTree; 

BiThrTree pre;
void InThreading(BiThrTree p){
	// pre��ȫ�ֱ�������ʼ��ʱ���Һ���ָ��Ϊ�գ���������������㿪ʼ������
	if(p){
		InThreading(p->lchild); // �������ݹ�������
		if(!p->lchild){ 		// p������Ϊ�� 
			p->LTag=1;
			p->lchild=pre;		// p������ָ��ǰ�� 
		}else{
			p->LTag=0;
		} 
		if(!pre->rchild){
			pre->RTag=1;		// ��pre���������� 
			pre->rchild=p;		// pre���Һ���ָ��ָ��p����̣� 
		}else{
			pre->RTag=0;
		}
		pre=p;					// ����preָ��p��ǰ�� 
		InThreading(p->rchild); // �������ݹ������� 
	} 
}

void InOrderThreading(BiThrTree &Thrt,BiThrTree T){
	// �������������T��������������������Thrtָ��ͷ���
	Thrt=(BiThrTree)malloc(sizeof(BiThrNode)); // ����ͷ��� 
	Thrt->LTag=0;							   // ͷ��������ӣ������ǿգ���������Ϊ���� 
	Thrt->RTag=1;							   // ͷ�����Һ���ָ��Ϊ������
	Thrt->rchild=Thrt;						   // ��ʼ��ʱ��ָ��ָ���Լ�
	if(!T)
		Thrt->lchild=T;
	else{
		Thrt->lchild=T;
		pre=Thrt;
		InThreading(T);
		pre->rchild=Thrt;
		pre->RTag=1;
		Thrt->rchild=pre; // ͷ����������	
	}
} 

/*
 * ��ָ��pָ����ڵ㡣
 * ��pΪ�ǿ������������ʱ��ִ�����²���
 * 	* ���������£����������½��*p,��������ĵ�һ�����
 *	* ����*p
 *	* ���������������ҵ�ǰ���*p�ĺ�̽�㲢���ʺ�̽�㣬ֱ��������Ϊ0���߱������� 
 *	* ת��p�������� 
 */
void InOrderTraverse_Thr(BiThrTree T){
	 // Tָ��ͷ��㣬ͷ��������lchildָ����ڵ�
	 // �������������������T�ķǵݹ��㷨����ÿ������Ԫ��ֱ�����
	BiThrTree p=T->lchild;
	while(p!=T){
		while(p->LTag==0)
			p=p->lchild;
		printf("%c ",p->data);
		while(p->RTag==1&&p->rchild!=T){
			p=p->rchild;
			printf("%c ",p->data); // �������������ʺ�̽�� 
		}
		p=p->rchild;			   // ת��p�������� 
	}
}

void CreateBiTree(BiThrTree &T){
	// ���մ����������������ֵ��һ���ַ������������������ʾ�Ķ�����T 
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
		T=NULL; // �ݹ������������
	else{
		T=(BiThrTree)malloc(sizeof(BiThrNode));
		T->data=ch;
		CreateBiTree(T->lchild); // �ݹ鴴��������
		CreateBiTree(T->rchild); // �ݹ鴴�������� 
	} 							 // else 
}
// ABC##DE#G##F### �����������ݣ�ͨ���ݹ飩
int main(){
	BiThrTree bt,thrt;
	pre=(BiThrTree)malloc(sizeof(BiThrNode));
	CreateBiTree(bt);
	InOrderThreading(thrt,bt);
	InOrderTraverse_Thr(thrt);
}
