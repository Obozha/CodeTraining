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

/* method��InitStack
 * description����ʼ��ջ 
 * param��
 *		LinkStack &S  ջָ�������  
 * return�� Status ����һ��״ֵ̬ OK 1 /ERROR -1
 */
Status InitStack(LinkStack &S) {
	S=NULL;
	return OK;
}

/* method��Push
 * description����ջ 
 * param��
 *		LinkStack &S  ջָ�������  
 *      ElemType e    ����Ϊ ElemType ����ջ���� 
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
 *		LinkStack &S  ջָ�������  
 *      ElemType &e    ����Ϊ ElemType ����ջ���ݵ����� 
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

/* method��StackEmpty
 * description���鿴ջ�Ƿ�Ϊ�� 
 * param��
 *		LinkStack S  ջָ��
 * return�� bool ջ���� ����true �շ���false 
 */
bool StackEmpty(LinkStack S){
	if(S!=NULL)
		return true;
	else
		return false;
}

struct ArcNode {
	int adjvex;
	struct ArcNode *nextarc;
	OtherInfo info;
};

typedef struct VNode {
	VerTexType data;   // ������Ϣ
	ArcNode *firstarc; // ָ���һ�������ö���ıߵ�ָ��
} VNode,AdjList[MVNum];

typedef struct {
	AdjList vertices;			// �ڽӱ�
	AdjList converse_vertices;	// ���ڽӱ�
	int vexnum,arcnum; 			// ͼ�ĵ�ǰ�������ͱ���
} ALGraph;

int visited[MVNum];
/* method��LocateVex
 * description�������򷵻�u�ڶ�����е��±ꣻ���򷵻�-1
 * param��
 *		ALGraph G  ͼ�Ľṹ��
 *		VerTexType u �����ֵ 
 * return�� int ���ض����±꣬û�оͷ���-1 
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
 * description�������ڽӱ��ʾ������������ͼ������ʹ���ڽӱ�����ڽӱ� 
 * param��
 *		ALGraph &G  ͼ�Ľṹ������ 
 * return�� Status ����һ��״ֵ̬ OK 1 /ERROR -1
 */
Status CreateDG(ALGraph &G) {
	int i,j,k;
	VerTexType v1,v2;
	cout<<"�������ܶ������ݣ��ܱ���:";
	cin>>G.vexnum>>G.arcnum;		// �����ܶ�����
	cout<<"�����붥������:";
	for(i=0; i<G.vexnum; i++) {
		cin>>G.vertices[i].data;	// ���붥��ֵ
		G.converse_vertices[i].data=G.vertices[i].data;
		G.vertices[i].firstarc=NULL;// ��ʼ��ͷ����ָ����ΪNULL
		G.converse_vertices[i].firstarc=NULL;
	}
	cout<<"������ÿ������������������:";
	for(k=0; k<G.arcnum; k++) {		// ������ߣ������ڽӱ�
		cin>>v1>>v2;				// ����һ������������������
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		// ȷ��v1��v2��G�е�λ�ã���������G.vertices�е����
		ArcNode* p1=(ArcNode*)malloc(sizeof(ArcNode));
		p1->adjvex=j;
		p1->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;

		ArcNode *p2=(ArcNode*)malloc(sizeof(ArcNode));
		p2->adjvex=i;
		p2->nextarc=G.converse_vertices[j].firstarc;
		G.converse_vertices[j].firstarc=p2;
	}
	return OK;
}

/* method��FindInDegree
 * description��������������ȴ�������indegree��
 * param��
 *		ALGraph G  ͼ�Ľṹ��
 *		int *indegree ��������ȵ�����ָ�� 
 * return�� void
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
 * description��������������ȴ�������indegree��
 * param��
 *		ALGraph G  ͼ�Ľṹ��
 *		int *tope  �������������ָ�� 
 * return�� bool true�޻���false�л� 
 */
bool TopologicalSort(ALGraph G,int *topo) {
	// ������ͼ��������������G�޻�·������G��һ��������������topo[]������true
	// ���򷵻�false
	int i,k,m,indegree[G.vexnum];
	FindInDegree(G,indegree); // �Ը���������ȣ����������indgree��
	LinkStack S;
	InitStack(S);
	for(i=0; i<G.vexnum; i++)
		if(indegree[i]==0)
			Push(S,i);
	m=0; // ������������
	while(StackEmpty(S)) {
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
	
	cout<<"��������:";
	for(i=0;i<G.vexnum;i++)
		cout<<topo[i]<<" ";
	
	if(m<G.vexnum)
		return false; // ������ͼ�л�·
	else
		return true;
}

/* method��TraverseGraphList
 * description������ͼ���ڽӱ�����ڽӱ� 
 * param��
 *		ALGraph G  ͼ�Ľṹ��
 * return�� void
 */
void TraverseGraphList(ALGraph G){
	int i;
	cout<<"�ڽӱ����"<<endl;
	for(i=0;i<G.vexnum;i++){
		cout <<"��ǰ���"<<G.vertices[i].data<<":";
		ArcNode* vptr=G.vertices[i].firstarc;
		while(vptr){
			cout<<vptr->adjvex<<" ";
			vptr=vptr->nextarc;
		}
		cout<<endl;
	}
	
	cout<<"���ڽӱ����"<<endl;
	for(i=0;i<G.vexnum;i++){
		cout <<"��ǰ���"<<G.converse_vertices[i].data<<":";
		ArcNode* vptr=G.converse_vertices[i].firstarc;
		while(vptr){
			cout<<vptr->adjvex<<" ";
			vptr=vptr->nextarc;
		}
		cout<<endl;
	}
}

// 6 8
// 0 1 2 3 4 5
//0 1 
//0 3
//2 1
//2 5
//1 5
//4 0
//4 1
//4 5

int main() {
	cout<<"AOV��Activity on Vextex���������"<<endl;
	 
	ALGraph G;
	
	
	// ����ͼ 
	CreateDG(G);
	
	// ����ͼ 
	int tope[G.vexnum];
	TraverseGraphList(G);

	// ��������ͼ 
	bool flag=TopologicalSort(G,tope);
}
