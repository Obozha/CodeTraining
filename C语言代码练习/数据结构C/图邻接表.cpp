#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MVNum 100
#define OK 1
typedef int Status;
typedef int OtherInfo;
typedef int VerTexType;

struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
	OtherInfo info;
};

typedef struct VNode{	// ������Ϣ 
	VerTexType data;
	ArcNode	*firstarc;	// ָ���һ�������ö���ıߵ�ָ�� 
}VNode,AdjList[MVNum];

typedef struct{
	AdjList vertices;
	int vexnum,arcnum;	// ͼ�ĵ�ǰ�������ͱ��� 
}ALGraph;

int visited[MVNum];
int LocateVex(ALGraph G,VerTexType u){
	// �����򷵻�u�ڶ�����е��±ꣻ���򷵻�-1
	int i;
	for(i=0;i<G.vexnum;i++){
		if(u==G.vertices[i].data){
			return i;
		} 
	} 
	return -1;
}

Status CreateUDG(ALGraph &G){
	// �����ڽӱ��ʾ������������ͼ
	int i,j,k;
	VerTexType v1,v2;
	cout<<"�������ܶ��������ܱ���:";
	cin>>G.vexnum>>G.arcnum;     		// �����ܶ��������ܱ��� 
	cout<<"�����붥������:";
	for(i=0;i<G.vexnum;i++){
		cin>>G.vertices[i].data; 		// ���붥��ֵ
		G.vertices[i].firstarc=NULL; 	// ��ʼ����ͷ����ָ����ΪNULL 
	}
	cout<<"������ÿ������������������"; 
	for(k=0;k<G.arcnum;k++){			// ������ߣ������ڽӱ�
		cin >> v1 >> v2;					// ����һ������������������
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		// ȷ��v1��v2��G��λ�ã���������G.vertices�е����
		ArcNode* p1=(ArcNode*)malloc(sizeof(ArcNode));; 	// ������һ���ԳƵ��µı߽��*p1
		p1->adjvex=j;										// �ڽӵ����Ϊj	
		p1->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;							// ���½��*p1���붥��vi�ı߱�ͷ�� 
		
		ArcNode* p2=(ArcNode*)malloc(sizeof(ArcNode));; 	// ������һ���ԳƵ��µı߽��*p1
		p2->adjvex=i;										// �ڽӵ����Ϊi	
		p2->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=p2;							// ���½��*p1���붥��vi�ı߱�ͷ�� 
	}
	return OK;
}

void TraverseGraphList(ALGraph G){
	int i;
	for(i=0;i<G.vexnum;i++){
		cout <<"��ǰ���Ϊ��"<< G.vertices[i].data<<" ";
		ArcNode* vptr=G.vertices[i].firstarc;
		while(vptr){
			cout<<vptr->adjvex<<" ";
			vptr=vptr->nextarc;
		}
		cout<<endl;
	}
}

void DFS_AL(ALGraph G,int v){
	// ͼGΪ�ڽӾ��󣬴ӵ�v���������������ȱ�������ͼG
	cout<<v;							// ���ʵ�v�����㣬���÷��ʱ�־������Ӧ����ֵΪtrue 
	visited[v]=true; 					// ���μ���ڽӾ���v���ڵ���
	ArcNode* p=G.vertices[v].firstarc;	// pָ��v�ı������һ���߽��
	while(p){
		if(!visited[p->adjvex]){
			DFS_AL(G,p->adjvex);
		}
			
		p=p->nextarc;
	} 
}

// 1 2 2 5 5 3 2 3 3 4 1 4 
int main(){
	ALGraph G;
	cout<<"��ʼ����ͼ ..."<<endl; 
	CreateUDG(G);
	TraverseGraphList(G);
	DFS_AL(G,0);
}
