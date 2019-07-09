/*
	��ʵ����Ҫʵ�ֶ������Ļ����������������н��ֵ������Ϊchar
	��ʵ����Ҫʵ��5��������
	1��void CreatBitree(BiTree &T)  //���������������������У��������ַ�'#'��ʾ����������������T
	2��void InOrderTraverse(BiTree T)   //�������������T
	3��void PreOrderTraverse(BiTree T)  //�������������T
	4��void PostOrderTraverse(BiTree T)  //�������������T
	5��bool SearchTree(BiTree T,char ch,BiTree &p)  //�ڶ�����T�в���ֵΪch�Ľ�㣬���ҳɹ�����������true,pָ��ý��,����������false��pΪ��
	6��int Depth(BiTree T) //�������T�����
	7��int NodeCount(BiTree T)  //�������T�н��ĸ���
	8��int LeafCount(BiTree T)  //�������T��Ҷ�ӽ�������
	9��int NodeCount1(BiTree T)  //�������T�ж�Ϊ1�Ľ�������
	10��int NodeCount2(BiTree T)   //�������T�ж�Ϊ2�Ľ�������
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//��������ṹ
typedef struct BiTNode {
	char data;      //������,��Ž��ֵ
	struct BiTNode *lchild,*rchild;  //���Һ���ָ��
} BiTNode,*BiTree; // ��������
//���������������������У��������ַ�'#'��ʾ����������������T
void CreatBitree(BiTree &T) {
	// ��ͬѧ�ǲ���˲���
	// �������������������н���ֵ��һ���ַ�����������������ʾ�Ķ�����T
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
		T=NULL;		// �ݹ�����������
	else {
		T=(BiTree)malloc(sizeof(BiTNode));	// ���ɸ�����
		T->data=ch; 			// �������������Ϊch
		CreatBitree(T->lchild);	// �ݹ鴴��������
		CreatBitree(T->rchild); // �ݹ鴴��������
	}

}

//�������T��ֵΪch�Ľ��Ĳ�Σ������p��ʾ��curlevel��ʾ��ǰT���ڵĲ�����
//��ֵ�ɹ�����true,ʧ�ܷ���false
bool level(BiTree T,char ch,int curlevel,int &p) {
	if(T==NULL)  //��TΪ����������false
		return false;
	if(T->data==ch) {  //��T��ֵΪch,�������pΪcurlevel
		p=curlevel;
		return true;
	} else { //��T��ֵΪch,������T������������ch���Ĳ�������ch��㲻��T���������У�����T������������ch���Ĳ���
		if(level(T->lchild,ch,curlevel+1,p))
			return true;
		else
			return level(T->rchild,ch,curlevel+1,p);
	}
}

//�������������T������������������
void InOrderTraverse(BiTree T) {
	//��ͬѧ�ǲ���˲���
	// �������������T�ĵݹ��㷨
	if(T) {
		InOrderTraverse(T->lchild); // �������������
		printf("%c ",T->data);
		InOrderTraverse(T->rchild); // �������������
	}
}

//�������������T������������������
void PreOrderTraverse(BiTree T) {
	//��ͬѧ�ǲ���˲���
	if(T) {
		printf("%c ",T->data);
		PreOrderTraverse(T->lchild); // �������������
		PreOrderTraverse(T->rchild); // �������������
	}
}

//�������������T�����������������
void PostOrderTraverse(BiTree T) {
	//��ͬѧ�ǲ���˲���
	if(T) {
		PostOrderTraverse(T->lchild); // �������������
		PostOrderTraverse(T->rchild); // �������������
		printf("%c ",T->data);
	}
}

bool flag=false;
//�ڶ�����T�в���ֵΪch�Ľ�㣬���ҳɹ�����������true,pָ��ý��,����������false��pΪ��
void SearchTree(BiTree T,char ch,BiTree &p) {
	//��ͬѧ�ǲ���˲���
	if(T) {
		if(T->data==ch) {
			p=T;
			flag=true;
		}
		SearchTree(T->lchild,ch,p);
		SearchTree(T->rchild,ch,p);
	}
}

//�������T�����
int Depth(BiTree T) {
	//��ͬѧ�ǲ���˲���
	int m,n;
	if(T==NULL)
		return 0; 		// ����ǿ��������Ϊ0���ݹ����
	else {
		m=Depth(T->lchild);
		n=Depth(T->rchild);
		if(m>n)
			return (m+1);
		else
			return (n+1);
	}

	return 0;  //������ò��������޸Ĵ��д���
}

//�������T�н������
int NodeCount(BiTree T) {
	//��ͬѧ�ǲ���˲���
	if(T==NULL)
		return 0;
	else
		return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
	return 0;  //������ò��������޸Ĵ��д���
}

//�������T��Ҷ�ӽ������
int LeafCount(BiTree T) {
	//��ͬѧ�ǲ���˲���
	// ������������������������Ҷ�ӽ�����Ŀ
	int m,n; // m,n�ֱ��ʾ����������Ҷ�ӵ���Ŀ
	if(T==NULL)
		return 0;
	else if(T->lchild==NULL&&T->rchild==NULL)
		return 1;
	else {
		m=LeafCount(T->lchild);
		n=LeafCount(T->rchild);
		return m+n;
	}
	return 0;  //������ò��������޸Ĵ��д���
}


int a1=0,a2;
//�������T�ж�Ϊ1�Ľ������
void NodeCount1(BiTree T) {
	//��ͬѧ�ǲ���˲���
	if(T) {
		if((T->lchild!=NULL&&T->rchild==NULL)||(T->lchild==NULL&&T->rchild!=NULL)) {
			a1++;
		}
		NodeCount1(T->lchild);
		NodeCount1(T->rchild);
	}
}

//�������T�ж�Ϊ2�Ľ������
void NodeCount2(BiTree T) {
	if(T) {
		if(T->lchild!=NULL&&T->rchild!=NULL) {
			a2++;
		}
		NodeCount2(T->lchild);
		NodeCount2(T->rchild);
	}
}

int main() {
	BiTree T,p=NULL;       //TΪ��������Ҫ�����Ķ�������
	char ch;    //ch��ʾ�ڶ�������Ҫ��ѯ�Ľ��
	cout<<"������Ҫ�����Ķ��������������������룬�������ַ�'#'����"<<endl;
	CreatBitree(T);  //��������Ķ������������У�������������T
	cout<<"������Ҫ��ѯ�Ľ��"<<endl;
	cin>>ch;
	int n;
	level(T,ch,1,n);  //��ֵΪch���Ĳ�������ʼʱ���Ĳ���Ϊ1
	cout<<"�ý��Ĳ��Ϊ"<<n<<endl;
	cout<<endl<<"����������Ϊ��"<<endl;
	InOrderTraverse(T);      //���������T�������������
	cout<<endl<<"����������Ϊ��"<<endl;
	PreOrderTraverse(T);     //���������T�������������
	cout<<endl<<"����������Ϊ��"<<endl;
	PostOrderTraverse(T);    //���������T�ĺ����������
	cout<<endl<<"�������ڶ�������Ҫ���ҵĽ�㣺"<<endl;
	rewind(stdin);   //������뻺����
	cin>>ch;
	SearchTree(T,ch,p);   //�ڶ�����T�в���ֵΪch�Ľ��
	if(flag)
		cout<<"�ڶ������в��ҳɹ�,����ֵΪ"<<p->data<<endl;
	else
		cout<<"�������в�����ֵΪ"<<ch<<"�Ľ��"<<endl;

	cout<<"�����������Ϊ"<<Depth(T)<<endl;
	cout<<"���������ܽ����Ϊ"<<NodeCount(T)<<endl;
	NodeCount1(T);
	NodeCount2(T);
	cout<<"Ҷ�ӽ��������Ϊ1���������Ϊ2������ֱ�Ϊ��"<<LeafCount(T)<<","<<a1<<","<<a2<<endl;
	return 0;
}
