#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MaxInt 32767		// ��ʾ����ֵ������
#define MVNum 100
#define OK 1
#define ERROR -1

typedef int VerTexType;
typedef int ArcType;
typedef int OtherInfo;
typedef int Status;
typedef int ElemType;
typedef struct StackNode {
	ElemType data;
	struct StackNode *next;
} StackNode,*LinkStack;

// ============================ջ����=============================
/* method��InitStack
 * description����ʼ��ջ
 * param��
 *		@LinkStack &S ����һ����ջ�ṹ��ָ��
 * return�� Status ����һ��״ֵ̬ OK 1 /ERROR -1
 */
Status InitStack(LinkStack &S) {
	S=NULL;
	return OK;
}

/* method��Push
 * description����ջ
 * param��
 *		@LinkStack &S ����һ����ջ�ṹ��ָ��
 *  	@ElemType e	 ��ջ���������
 * return�� Status ����һ��״ֵ̬ OK 1 /ERROR -1
 */
Status Push(LinkStack &S,ElemType e) {
	StackNode* p=(StackNode*)malloc(sizeof(StackNode));
	p->data=e;
	p->next=S;
	S=p;
	return OK;
}

/* method��Pop
 * description����ջ
 * param��
 *		@LinkStack &S ����һ����ջ�ṹ��ָ��
 *  	@ElemType &e  ��������ΪElemType���������� 
 * return�� Status ����һ��״ֵ̬ OK 1 /ERROR -1
 */
Status Pop(LinkStack &S,ElemType &e) {
	// ɾ��sΪջ��Ԫ�أ���e������ֵ
	if(S==NULL)
		return ERROR; // ջ��
	e=S->data;
	StackNode* p=S;
	S=S->next;	// �޸�ջ��ָ��
	delete p;
	return OK;
}

/* method��IsStackEmpty
 * description���鿴ջ�ղ���
 * param��
 *		@LinkStack S ����һ����ջ�ṹ��ָ��
 * return�� bool true or false ����ǿ� �پ��ǲ���
 */
bool IsStackEmpty(LinkStack S) {
	if(S==NULL)
		return true;
	else
		return false;
}

// ============================ջ����=============================

//�߽��
struct ArcNode {
	int adjvex;
	struct ArcNode *nextarc;
	OtherInfo weight;
};

// ������
typedef struct VNode {
	VerTexType data;   // ������Ϣ
	ArcNode *firstarc; // ָ���һ�������ö���ıߵ�ָ��
} VNode,AdjList[MVNum];

// ���ڽӱ�ṹ������ʾͼ
typedef struct {
	AdjList vertices;			// �ڽӱ�
	AdjList converse_vertices;	// ���ڽӱ�
	int vexnum,arcnum; 			// ͼ�ĵ�ǰ�������ͱ���
} ALGraph;

int visited[MVNum];

/* method��LocateVex
 * description�������򷵻�u�ڶ�����е��±ꣻ���򷵻�-1
 * param��
 *		@ALGraph G     ͼ�Ľṹ��
 *		@VerTexType u  ����u
 * return�� int ���ض����±꣬û�о���-1
 */
int LocateVex(ALGraph G,VerTexType u) {
	int i;
	for(i=0; i<G.vexnum; i++) {
		if(u==G.vertices[i].data) {
			return i;
		}
	}
	return -1;
}

/* method��CreateDG
 * description������һ�������� ���ڽӱ�
 * param��
 *		@ALGraph &G     ͼ�Ľṹ��
 * return�� Status ����һ��״ֵ̬ OK 1 /ERROR -1
 */
Status CreateDN(ALGraph &G) {
	int i,j,k,w;
	VerTexType v1,v2;
	cout<<"�������ܶ������ݣ��ܱ�����";
	cin>>G.vexnum>>G.arcnum;
	cout<<"�����붥�����ݣ�";
	for(i=0; i<G.vexnum; i++) {
		cin>>G.vertices[i].data;	// ���붥��ֵ
		G.converse_vertices[i].data=G.vertices[i].data;
		G.vertices[i].firstarc=NULL;// ��ʼ��ͷ����ָ����ΪNULL
		G.converse_vertices[i].firstarc=NULL;
	}
	cout<<"������ÿ�������������������Ȩֵ��"<<endl;
	for(k=0; k<G.arcnum; k++) {		// ������ߣ������ڽӱ�
		cin>>v1>>v2>>w;				// ����һ������������������
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		// ȷ��v1��v2��G�е�λ�ã���������G.vertices�е����
		ArcNode* p1=(ArcNode*)malloc(sizeof(ArcNode));
		p1->adjvex=j;
		p1->weight=w;
		p1->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;

		ArcNode *p2=(ArcNode*)malloc(sizeof(ArcNode));
		p2->adjvex=i;
		p2->weight=w;
		p2->nextarc=G.converse_vertices[j].firstarc;
		G.converse_vertices[j].firstarc=p2;
	}
	return OK;
}

/* method��FindInDegree
 * description��������������ȴ�������indegree��
 * param��
 *		@ALGraph G     ͼ�Ľṹ��
 *	 	@int *indegree indegree���� ���������ȸ���
 * return�� Status ����һ��״ֵ̬ OK 1 /ERROR -1
 */
void FindInDegree(ALGraph G,int *indegree) {
	int i,count;
	for(i=0; i<G.vexnum; i++) {
		count=0;
		ArcNode *p=G.converse_vertices[i].firstarc;
		while(p) {
			p=p->nextarc;
			count++;
		}
		indegree[i]=count;
	}
}

/* method��TopologicalSort
 * description��������ͼ��������������G�޻�·������G��һ��������������topo[]������true
 *				���򷵻�false
 * param��
 *		@ALGraph G     ͼ�Ľṹ��
 *	 	@int *topo 	   topo���� ����AOV�㷨���ɵ�topo��������
 * return�� bool �Ƿ��л�·��û�оͷ���true���оͷ���false
 */
bool TopologicalSort(ALGraph G,int *topo) {
	int i,k,m,indegree[G.vexnum];

	FindInDegree(G,indegree);
	// �Ը���������ȣ����������indgree��

	LinkStack S;
	InitStack(S);
	for(i=0; i<G.vexnum; i++)
		if(indegree[i]==0)
			Push(S,i);
	m=0; // ������������
	while(!IsStackEmpty(S)) {
		Pop(S,i);  // iΪ�����λ��
		topo[m]=i; // ����i�����㱣����������
		m++;	   // ������������
		ArcNode* p=G.vertices[i].firstarc; // pָ��vi�ĵ�һ�������
		while(p!=NULL) { // ��i�Ŷ����ÿ���ڽӵ���ȼ�1
			k=p->adjvex;
			indegree[k]--;
			if(indegree[k]==0)
				Push(S,k);
			p=p->nextarc;
		}
	}
	if(m<G.vexnum)
		return false; // ������ͼ�л�·
	else
		return true;
}

/* method��TraverseGraphList
 * description�������ڽӱ�����ڽӱ�
 * param��
 *		@ALGraph G     ͼ�Ľṹ��
 * return�� void
 */
void TraverseGraphList(ALGraph G) {
	int i;
	cout<<"-------�ڽӱ����-------"<<endl;
	for(i=0; i<G.vexnum; i++) {
		cout <<"��ǰ���Ϊ��"<< G.vertices[i].data<<" "<<"->";
		ArcNode* vptr=G.vertices[i].firstarc;
		while(vptr) {
			cout<<vptr->adjvex<<" ";
			vptr=vptr->nextarc;
		}
		cout<<endl;
	}
	cout<<"-------���ڽӱ����-------"<<endl;
	for(i=0; i<G.vexnum; i++) {
		cout <<"��ǰ���Ϊ��"<< G.converse_vertices[i].data<<" ">"->";
		ArcNode* vptr=G.converse_vertices[i].firstarc;
		while(vptr) {
			cout<<vptr->adjvex<<" ";
			vptr=vptr->nextarc;
		}
		cout<<endl;
	}
}

/* method��CriticalPath
 * description���ؼ�·�� AOE Ѱ��ͼ�еĹؼ�·��
 * param��
 *		@ALGraph G     ͼ�Ľṹ��
 * return�� bool true������ҳɹ� false˵���л�����ʧ��
 */
bool CriticalPath(ALGraph G) {
	int i,j,k,topo[G.vexnum],vl[G.vexnum],ve[G.vexnum],ed[G.arcnum],ld[G.arcnum];
	if(!TopologicalSort(G,topo))
		return false; // ��G���л��������ؼ�·��ʧ��
	for(i=0; i<G.vexnum; i++) { // ����������
		ve[i]=0;
	} // ��ʼ�����¼������翪ʼʱ��Ϊ0
	for(i=0; i<G.vexnum; i++) { // �����˴�������¼�����ٷ����¼�
		k=topo[i];
		ArcNode* p=G.vertices[k].firstarc; // pָ���k������ĵ�һ�������
		while(p!=NULL) {
			j=p->adjvex;
			if(ve[j]<ve[k]+p->weight)
				ve[j]=ve[k]+p->weight; // ����ve[j]
			p=p->nextarc;
		}
	}

	for(i=0; i<G.vexnum; i++)
		vl[i]=ve[G.vexnum-1]; // ��ʼ���������¼�����ٷ���ʱ��
	for(i=G.vexnum-1; i>=0; i--) { // ��������������¼����������¼�
		k=topo[i];
		ArcNode* p=G.vertices[k].firstarc; // pָ���k������ĵ�һ�������
		while(p!=NULL) {
			j=p->adjvex;
			if(vl[k]>vl[j]-p->weight)
				vl[k]=vl[j]-p->weight; // ����vl[k]
			p=p->nextarc;
		}
	}


	int z=0;
	cout<<"�����ؼ�·��"<<endl;
	for(i=0; i<G.vexnum; i++) { // ���������磬�������¼����жϹؼ��
		ArcNode *p=G.vertices[i].firstarc; // pָ���i������ĵ�һ�������
		while(p!=NULL) {
			j=p->adjvex; // ����ȡ��i���ڽӵ�j
			
			int e=ve[i];     // ����<vi,vj>�����翪ʼʱ��
			ed[z]=ve[i];	 // ����翪ʼʱ�� 

			int l=vl[j]-p->weight;
			ld[z]=vl[j]-p->weight;
			// ���ٿ�ʼʱ�� 
			z++;

			if(e==l)
				cout<<G.vertices[i].data<<" "<<G.vertices[j].data<<" "<<endl;
			p=p->nextarc; // ������һ���
		}
	}
	cout<<endl;
	cout<<"����ķ���ʱ��"<<endl; 
	cout<<"����i\t|ve(i)\t|vl(i)"<<endl;
	for(i=0; i<G.vexnum; i++) {
		cout<<i<<"\t|"<<ve[i]<<"\t|"<<vl[i]<<endl;
	}
	cout<<endl;
	cout<<"��Ŀ�ʼʱ��"<<endl; 
	cout<<"�ai\te(i)\tl(i)\tl(i)-e(i)"<<endl;
	for(i=0; i<G.arcnum; i++) {
		cout<<"a"<<i<<"\t|"<<ed[i]<<"\t|"<<ld[i]<<"\t|"<<ld[i]-ed[i]<<endl;
	}
	return true;
}

int main() {
	cout<<"AOE��Activity on Edge���������"<<endl;

	// ����һ��ͼ
	ALGraph G;

	// ����������
	CreateDN(G);

	//  ��ʼ����������
	int topo[G.vexnum];

	cout<<endl;
	// �����ڽӱ�����ڽӱ�
	TraverseGraphList(G);
	cout<<endl;

	// AOV �����������鿴��ǰͼ�Ƿ��л�
	bool flag=TopologicalSort(G,topo);

	cout<<endl;
	// ����topo����
	cout<<"topo���飺";
	for(int i=0; i<G.vexnum; i++)
		cout<<topo[i]<<" ";
	cout<<endl<<endl;


	// �ؼ�·��
	CriticalPath(G);
}
