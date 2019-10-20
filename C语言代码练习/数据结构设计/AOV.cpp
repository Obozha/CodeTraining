#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MaxInt 32767		// 表示极大值，即∞
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

/* method：InitStack
 * description：初始化栈 
 * param：
 *		LinkStack &S  栈指针的引用  
 * return： Status 返回一个状态值 OK 1 /ERROR -1
 */
Status InitStack(LinkStack &S) {
	S=NULL;
	return OK;
}

/* method：Push
 * description：入栈 
 * param：
 *		LinkStack &S  栈指针的引用  
 *      ElemType e    类型为 ElemType 的入栈数据 
 * return： Status 返回一个状态值 OK 1 /ERROR -1
 */
Status Push(LinkStack &S,ElemType e) {
	StackNode* p=(StackNode*)malloc(sizeof(StackNode));
	p->data=e;
	p->next=S;
	S=p;
	return OK;
}

/* method：Pop
 * description：出栈 
 * param：
 *		LinkStack &S  栈指针的引用  
 *      ElemType &e    类型为 ElemType 的入栈数据的引用 
 * return： Status 返回一个状态值 OK 1 /ERROR -1
 */
Status Pop(LinkStack &S,ElemType &e) {
	// 删除s为栈顶元素，用e返回其值
	if(S==NULL)
		return ERROR; // 栈空
	e=S->data;
	StackNode* p=S;
	S=S->next;	// 修改栈顶指针
	delete p;
	return OK;
}

/* method：StackEmpty
 * description：查看栈是否为空 
 * param：
 *		LinkStack S  栈指针
 * return： bool 栈不空 返回true 空返回false 
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
	VerTexType data;   // 顶点信息
	ArcNode *firstarc; // 指向第一条依附该顶点的边的指针
} VNode,AdjList[MVNum];

typedef struct {
	AdjList vertices;			// 邻接表
	AdjList converse_vertices;	// 逆邻接表
	int vexnum,arcnum; 			// 图的当前定点数和边数
} ALGraph;

int visited[MVNum];
/* method：LocateVex
 * description：存在则返回u在顶点表中的下标；否则返回-1
 * param：
 *		ALGraph G  图的结构体
 *		VerTexType u 顶点的值 
 * return： int 返回顶点下标，没有就返回-1 
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

/* method：CreateDG
 * description：采用邻接表表示法，创建有向图，这里使用邻接表和逆邻接表 
 * param：
 *		ALGraph &G  图的结构体引用 
 * return： Status 返回一个状态值 OK 1 /ERROR -1
 */
Status CreateDG(ALGraph &G) {
	int i,j,k;
	VerTexType v1,v2;
	cout<<"请输入总顶点数据，总边数:";
	cin>>G.vexnum>>G.arcnum;		// 输入总定点数
	cout<<"请输入顶点数据:";
	for(i=0; i<G.vexnum; i++) {
		cin>>G.vertices[i].data;	// 输入顶点值
		G.converse_vertices[i].data=G.vertices[i].data;
		G.vertices[i].firstarc=NULL;// 初始化头结点的指针域为NULL
		G.converse_vertices[i].firstarc=NULL;
	}
	cout<<"请输入每个边依附的两个顶点:";
	for(k=0; k<G.arcnum; k++) {		// 输入各边，构造邻接表
		cin>>v1>>v2;				// 输入一条边依附的两个顶点
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		// 确定v1和v2在G中的位置，即顶点在G.vertices中的序号
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

/* method：FindInDegree
 * description：求出各顶点的入度存入数组indegree中
 * param：
 *		ALGraph G  图的结构体
 *		int *indegree 各顶点入度的数组指针 
 * return： void
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

/* method：TopologicalSort
 * description：求出各顶点的入度存入数组indegree中
 * param：
 *		ALGraph G  图的结构体
 *		int *tope  拓扑排序数组的指针 
 * return： bool true无环，false有环 
 */
bool TopologicalSort(ALGraph G,int *topo) {
	// 对有向图进行拓扑排序，若G无回路，生成G的一个拓扑排序序列topo[]并返回true
	// 否则返回false
	int i,k,m,indegree[G.vexnum];
	FindInDegree(G,indegree); // 对各顶点求入度，存放在数组indgree中
	LinkStack S;
	InitStack(S);
	for(i=0; i<G.vexnum; i++)
		if(indegree[i]==0)
			Push(S,i);
	m=0; // 对输出顶点计数
	while(StackEmpty(S)) {
		Pop(S,i);  // i为顶点的位置
		topo[m]=i; // 将第i个顶点保存在拓扑序
		m++;	   // 对输出顶点计数
		ArcNode* p=G.vertices[i].firstarc; // p指向vi的第一个弧结点
		while(p!=NULL) { // 对i号顶点的每个邻接点入度减1
			k=p->adjvex;
			indegree[k]--;
			if(indegree[k]==0)
				Push(S,k);
			p=p->nextarc;
		}
	}
	
	cout<<"拓扑序列:";
	for(i=0;i<G.vexnum;i++)
		cout<<topo[i]<<" ";
	
	if(m<G.vexnum)
		return false; // 该有向图有回路
	else
		return true;
}

/* method：TraverseGraphList
 * description：遍历图的邻接表和逆邻接表 
 * param：
 *		ALGraph G  图的结构体
 * return： void
 */
void TraverseGraphList(ALGraph G){
	int i;
	cout<<"邻接表遍历"<<endl;
	for(i=0;i<G.vexnum;i++){
		cout <<"当前结点"<<G.vertices[i].data<<":";
		ArcNode* vptr=G.vertices[i].firstarc;
		while(vptr){
			cout<<vptr->adjvex<<" ";
			vptr=vptr->nextarc;
		}
		cout<<endl;
	}
	
	cout<<"逆邻接表遍历"<<endl;
	for(i=0;i<G.vexnum;i++){
		cout <<"当前结点"<<G.converse_vertices[i].data<<":";
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
	cout<<"AOV（Activity on Vextex）代码测试"<<endl;
	 
	ALGraph G;
	
	
	// 创建图 
	CreateDG(G);
	
	// 遍历图 
	int tope[G.vexnum];
	TraverseGraphList(G);

	// 拓扑排序图 
	bool flag=TopologicalSort(G,tope);
}
