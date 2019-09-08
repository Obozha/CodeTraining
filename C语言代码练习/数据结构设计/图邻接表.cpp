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

typedef struct VNode{	// 顶点信息 
	VerTexType data;
	ArcNode	*firstarc;	// 指向第一条依附该顶点的边的指针 
}VNode,AdjList[MVNum];

typedef struct{
	AdjList vertices;
	int vexnum,arcnum;	// 图的当前顶点数和边数 
}ALGraph;

int visited[MVNum];
int LocateVex(ALGraph G,VerTexType u){
	// 存在则返回u在顶点表中的下标；否则返回-1
	int i;
	for(i=0;i<G.vexnum;i++){
		if(u==G.vertices[i].data){
			return i;
		} 
	} 
	return -1;
}

Status CreateUDG(ALGraph &G){
	// 采用邻接表表示法，创建无向图
	int i,j,k;
	VerTexType v1,v2;
	cout<<"请输入总顶点数，总边数:";
	cin>>G.vexnum>>G.arcnum;     		// 输入总顶点数，总边数 
	cout<<"请输入顶点数据:";
	for(i=0;i<G.vexnum;i++){
		cin>>G.vertices[i].data; 		// 输入顶点值
		G.vertices[i].firstarc=NULL; 	// 初始化表头结点的指针域为NULL 
	}
	cout<<"请输入每个边依附的两个顶点"; 
	for(k=0;k<G.arcnum;k++){			// 输入各边，构造邻接表
		cin >> v1 >> v2;					// 输入一条边依附的两个顶点
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		// 确定v1和v2在G中位置，即顶点在G.vertices中的序号
		ArcNode* p1=(ArcNode*)malloc(sizeof(ArcNode));; 	// 生成另一个对称的新的边结点*p1
		p1->adjvex=j;										// 邻接点序号为j	
		p1->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;							// 将新结点*p1插入顶点vi的边表头部 
		
		ArcNode* p2=(ArcNode*)malloc(sizeof(ArcNode));; 	// 生成另一个对称的新的边结点*p1
		p2->adjvex=i;										// 邻接点序号为i	
		p2->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=p2;							// 将新结点*p1插入顶点vi的边表头部 
	}
	return OK;
}

void TraverseGraphList(ALGraph G){
	int i;
	for(i=0;i<G.vexnum;i++){
		cout <<"当前结点为："<< G.vertices[i].data<<" ";
		ArcNode* vptr=G.vertices[i].firstarc;
		while(vptr){
			cout<<vptr->adjvex<<" ";
			vptr=vptr->nextarc;
		}
		cout<<endl;
	}
}

void DFS_AL(ALGraph G,int v){
	// 图G为邻接矩阵，从第v个顶点出发深度优先遍历搜索图G
	cout<<v;							// 访问第v个顶点，并置访问标志数组相应分量值为true 
	visited[v]=true; 					// 依次检查邻接矩阵v所在的行
	ArcNode* p=G.vertices[v].firstarc;	// p指向v的边链表第一个边结点
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
	cout<<"开始创建图 ..."<<endl; 
	CreateUDG(G);
	TraverseGraphList(G);
	DFS_AL(G,0);
}
