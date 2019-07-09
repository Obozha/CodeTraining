#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef char TElemType;
//��������ṹ
typedef struct BiTNode {
	TElemType data;       //������,��Ž��ֵ
	struct BiTNode *lchild,*rchild;      //���Һ���ָ��
} BiTNode,*BiTree; // ��������

//������������ṹ
typedef struct BiThrNode {
	TElemType data;        //�����򣬴�Ž��ֵ
	struct BiThrNode *lchild,*rchild;          //���Һ���ָ��
	int LTag,RTag;    //���ұ�־��0��ʾָ�룬1��ʾ����
} BiThrNode,*BiThrTree;  //��������ṹ

//����������������ʱ��preָ��
BiThrNode *pre=NULL;

//���������������������У��������ַ�","��ʾ����������������
void creatbitree(BiTree &T) {
	char ch;
	ch=getchar();
	if(ch==',')     //����ʱ�����
		T=NULL;
	else {    //�������ǿգ��ݹ齨���Ӧ�Ķ�������
		T=(BiTNode *)malloc(sizeof(BiTNode));   //������ռ�
		if(!T)  exit(-1);   //�洢�ռ�����ʧ�ܣ��˳�����
		T->data =ch;        //Ϊ��㸳ֵ
		creatbitree(T->lchild);   //�ݹ鴴��T���������Ķ�������
		creatbitree(T->rchild);   //�ݹ鴴��T���������Ķ�������
	}
}

//�������������T
void inorder(BiTree T) {
	if(T) {
		//�����ע�����ݣ������油�����
		//�������T��������
		inorder(T->lchild);
		//���ʽ��T
		cout<<T->data;
		//�������T��������
		inorder(T->rchild);
	}
}

//�������������T
void preorder(BiTree T) {
	if(T) {
		//�����ע�����ݣ������油�����
		//���ʽ��T
		cout<<T->data;
		//�������T��������
		preorder(T->lchild);
		//�������T��������
		preorder(T->rchild);
	}
}

//�������������T
void postorder(BiTree T) {
	if(T) {
		//�����ע�����ݣ������油�����
		//�������T��������
		postorder(T->lchild);
		//�������T��������
		postorder(T->rchild);
		//���ʽ��T
		cout<<T->data;
	}
}

//����������������У��������ַ�","��ʾ��������������������
void creatbitree1(BiThrTree &T) {
	char ch;
	ch=getchar();
	if(ch==',')       //����ʱ�����
		T=NULL;
	else {     //���ǿ�ʱ
		T=(BiThrNode *)malloc(sizeof(BiThrNode));    //������ռ�
		if(!T)  exit(-1);   //�洢�ռ�����ʧ�ܣ��˳�����
		T->data =ch;        //Ϊ��㸳ֵ
		creatbitree1(T->lchild);    //�ݹ鴴��T���������Ķ�������
		creatbitree1(T->rchild);    //�ݹ鴴��T���������Ķ�������
	}
}


//����������������T
void inthread(BiThrTree &T) {
	if(T) {
		inthread(T->lchild);   //����������T��������
		if(pre!=NULL) {   //����pre���������ʱ�շ��ʵĽ�㣩����rtag��rchild��TΪ��ǰ���ڷ��ʵĽ��
			if(pre->rchild ==NULL) { //��pre����ָ����rchildΪ�գ��������Ϊ����
				//�����ע�Ͳ���˴�����
				pre->RTag=1;   // ��pre���������� 
				pre->rchild=T; // pre�к���ָ��p����̣� 
			} else       //��pre����ָ����rchild�ǿգ�������rtagֵ
				pre->RTag =0;
		}
		if(T->lchild ==NULL) { //����ǰ���ڷ��ʵĽ��(T)��ltag��lchild
			//�����ע�Ͳ���˴�����
			T->RTag=1;	// ��pre���������� 
			T->lchild=pre;// pre���Һ���ָ��ָ��p����̣� 
		} else      //��T����ָ����lchild�ǿգ�������ltagֵ
			T->LTag =0;
		pre=T;     //����ǰ����ɸոշ��ʹ��Ľ��
		inthread(T->rchild );   //����������T��������
	}
}

//���������������У���pΪ�������ұ����ĵ�һ�����
BiThrTree first(BiThrTree p) {
	if(p) {
		while(p->LTag ==0) {  //�������������з��ʵĵ�һ������Ϊ�����µĽ�㣬Ѱ�������µĽ��
			p=p->lchild;
		}
		return p;    //�����ҵ��ĵ�һ�����
	} else 
		return NULL;
}

//���������������в��ҽ��p��������,���������ҵ���p��������
BiThrTree next(BiThrTree p) {
	if(p) {
		if(p->RTag ==1) { //��pû���Һ��ӣ���������Ϊ��
			//�����ע�Ͳ���˴�����
			return p->rchild;
		} else {  //��p���Һ��ӣ���������Ϊ��
			//�����ע�Ͳ���˴�����
			first(p->rchild);
		}
	}
}

//������TΪ������������������
void intravers(BiThrTree T) {
	BiThrNode *s;
	if(T) {
		//��ͨ��first�����ұ���ʱ�ĵ�һ�����s
		//�����ע�Ͳ���˴�����
		s=first(T);
		while(s) {
			printf("%5c",s->data );    //������ֵ
			//��s�ĺ�̽��
			//�����ע�Ͳ���˴�����
			s=next(s);
		}
	}
}

//��������������T�в���ֵΪch�Ľ��
void searchthrtree(BiThrTree T,char ch) {
	BiThrNode *s;
	if(T) {
		s=first(T);
		while(s&&s->data !=ch) {
			s=next(s);
		}
		if(s==NULL)     //�������������������һ������rchildΪNULL��s=NULL,��ζ�Ŷ�������������������
			printf("û�иý�㣡\n");
		else
			printf("���ҳɹ���\n");
	}
}

bool flag;
void searchtree(BiTree T,char ch) {
	if(T) { // ���������ǿ�
		if(ch==T->data) {
			flag=true;
		}
		searchtree(T->lchild,ch); // ǰ�����������
		searchtree(T->rchild,ch); // ǰ�������������
	}
}

// ABC,,DE,G,,F,,,
int main() {
	BiTree T;       //TΪ��������Ҫ�����Ķ�������
	BiThrTree T1;   //T1Ϊ��������Ҫ�����Ķ�����������
	char ch,ch1;    //ch��ch1�ֱ��ʾ�ڶ�������������������Ҫ��ѯ�Ľ��
	bool t;
	printf("������Ҫ�����Ķ��������������������룬�������ַ�','����\n");
	creatbitree(T);  //��������Ķ������������У�������������T
	printf("\n����������Ϊ��");
	inorder(T);      //���������T�������������
	printf("\n����������Ϊ��");
	preorder(T);     //���������T�������������
	printf("\n����������Ϊ��");
	postorder(T);    //���������T�ĺ����������
	printf("\n�������ڶ�������Ҫ���ҵĽ�㣺");
	rewind(stdin);   //������뻺����
	scanf("%c",&ch1);
	searchtree(T,ch1);   //�ڶ�����T�в���ֵΪch1�Ľ��
	if(flag) printf("�ڶ������в��ҳɹ�\n");
	else printf("�ڶ������в��Ҳ��ɹ�\n");

	//���²�������������������Ϊ����������������������Ľ��������������Ҳ���
	printf("������Ҫ�����������������������������������룬�������ַ�','����\n");
	rewind(stdin);
	creatbitree1(T1);  //��������Ķ������������У�������������T1
	inthread(T1);      //��T1��������������������������������
	printf("���������������ı������Ϊ��");
	intravers(T1);     //��������������T1���б������������������
	printf("\n������������������������Ҫ���ҵĽ�㣺\n");
	rewind(stdin);
	scanf("%c",&ch);
	searchthrtree(T1,ch);  //������������T1�в���ֵΪch�Ľ��
}
