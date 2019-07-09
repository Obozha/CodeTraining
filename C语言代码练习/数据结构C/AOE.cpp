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

// ============================栈方法=============================
/* method：InitStack
 * description：初始化栈
 * param：
 *		@LinkStack &S 传入一个链栈结构体指针
 * return： Status 返回一个状态值 OK 1 /ERROR -1
 */
Status InitStack(LinkStack &S) {
	S=NULL;
	return OK;
}

/* method：Push
 * description：入栈
 * param：
 *		@LinkStack &S 传入一个链栈结构体指针
 *  	@ElemType e	 入栈传入的数据
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
 *		@LinkStack &S 传入一个链栈结构体指针
 *  	@ElemType &e  插入类型为ElemType的数据引用 
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

/* method：IsStackEmpty
 * description：查看栈空不空
 * param：
 *		@LinkStack S 传入一个链栈结构体指针
 * return： bool true or false 真就是空 假就是不空
 */
bool IsStackEmpty(LinkStack S) {
	if(S==NULL)
		return true;
	else
		return false;
}

// ============================栈方法=============================

//边结点
struct ArcNode {
	int adjvex;
	struct ArcNode *nextarc;
	OtherInfo weight;
};

// 顶点结点
typedef struct VNode {
	VerTexType data;   // 顶点信息
	ArcNode *firstarc; // 指向第一条依附该顶点的边的指针
} VNode,AdjList[MVNum];

// 用邻接表结构体来表示图
typedef struct {
	AdjList vertices;			// 邻接表
	AdjList converse_vertices;	// 逆邻接表
	int vexnum,arcnum; 			// 图的当前定点数和边数
} ALGraph;

int visited[MVNum];

/* method：LocateVex
 * description：存在则返回u在顶点表中的下标；否则返回-1
 * param：
 *		@ALGraph G     图的结构体
 *		@VerTexType u  顶点u
 * return： int 返回顶点下标，没有就是-1
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
 * description：创建一个有向网 （邻接表）
 * param：
 *		@ALGraph &G     图的结构体
 * return： Status 返回一个状态值 OK 1 /ERROR -1
 */
Status CreateDN(ALGraph &G) {
	int i,j,k,w;
	VerTexType v1,v2;
	cout<<"请输入总顶点数据，总边数：";
	cin>>G.vexnum>>G.arcnum;
	cout<<"请输入顶点数据：";
	for(i=0; i<G.vexnum; i++) {
		cin>>G.vertices[i].data;	// 输入顶点值
		G.converse_vertices[i].data=G.vertices[i].data;
		G.vertices[i].firstarc=NULL;// 初始化头结点的指针域为NULL
		G.converse_vertices[i].firstarc=NULL;
	}
	cout<<"请输入每个边依附的两个顶点和权值："<<endl;
	for(k=0; k<G.arcnum; k++) {		// 输入各边，构造邻接表
		cin>>v1>>v2>>w;				// 输入一条边依附的两个顶点
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		// 确定v1和v2在G中的位置，即顶点在G.vertices中的序号
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

/* method：FindInDegree
 * description：求出各顶点的入度存入数组indegree中
 * param：
 *		@ALGraph G     图的结构体
 *	 	@int *indegree indegree数组 各顶点的入度个数
 * return： Status 返回一个状态值 OK 1 /ERROR -1
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
 * description：对有向图进行拓扑排序，若G无回路，生成G的一个拓扑排序序列topo[]并返回true
 *				否则返回false
 * param：
 *		@ALGraph G     图的结构体
 *	 	@int *topo 	   topo数组 根据AOV算法生成的topo线性序列
 * return： bool 是否有回路，没有就返回true，有就返回false
 */
bool TopologicalSort(ALGraph G,int *topo) {
	int i,k,m,indegree[G.vexnum];

	FindInDegree(G,indegree);
	// 对各顶点求入度，存放在数组indgree中

	LinkStack S;
	InitStack(S);
	for(i=0; i<G.vexnum; i++)
		if(indegree[i]==0)
			Push(S,i);
	m=0; // 对输出顶点计数
	while(!IsStackEmpty(S)) {
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
	if(m<G.vexnum)
		return false; // 该有向图有回路
	else
		return true;
}

/* method：TraverseGraphList
 * description：遍历邻接表和逆邻接表
 * param：
 *		@ALGraph G     图的结构体
 * return： void
 */
void TraverseGraphList(ALGraph G) {
	int i;
	cout<<"-------邻接表遍历-------"<<endl;
	for(i=0; i<G.vexnum; i++) {
		cout <<"当前结点为："<< G.vertices[i].data<<" "<<"->";
		ArcNode* vptr=G.vertices[i].firstarc;
		while(vptr) {
			cout<<vptr->adjvex<<" ";
			vptr=vptr->nextarc;
		}
		cout<<endl;
	}
	cout<<"-------逆邻接表遍历-------"<<endl;
	for(i=0; i<G.vexnum; i++) {
		cout <<"当前结点为："<< G.converse_vertices[i].data<<" ">"->";
		ArcNode* vptr=G.converse_vertices[i].firstarc;
		while(vptr) {
			cout<<vptr->adjvex<<" ";
			vptr=vptr->nextarc;
		}
		cout<<endl;
	}
}

/* method：CriticalPath
 * description：关键路径 AOE 寻找图中的关键路径
 * param：
 *		@ALGraph G     图的结构体
 * return： bool true就算查找成功 false说明有环查找失败
 */
bool CriticalPath(ALGraph G) {
	int i,j,k,topo[G.vexnum],vl[G.vexnum],ve[G.vexnum],ed[G.arcnum],ld[G.arcnum];
	if(!TopologicalSort(G,topo))
		return false; // 若G中有环，则求解关键路径失败
	for(i=0; i<G.vexnum; i++) { // 按拓扑排序
		ve[i]=0;
	} // 初始化各事件的最早开始时间为0
	for(i=0; i<G.vexnum; i++) { // 按拓扑次序求各事件的最迟发生事件
		k=topo[i];
		ArcNode* p=G.vertices[k].firstarc; // p指向第k个顶点的第一个弧结点
		while(p!=NULL) {
			j=p->adjvex;
			if(ve[j]<ve[k]+p->weight)
				ve[j]=ve[k]+p->weight; // 更新ve[j]
			p=p->nextarc;
		}
	}

	for(i=0; i<G.vexnum; i++)
		vl[i]=ve[G.vexnum-1]; // 初始化各顶点事件的最迟发生时间
	for(i=G.vexnum-1; i>=0; i--) { // 按拓扑逆序求各事件的最晚发生事件
		k=topo[i];
		ArcNode* p=G.vertices[k].firstarc; // p指向第k个顶点的第一个弧结点
		while(p!=NULL) {
			j=p->adjvex;
			if(vl[k]>vl[j]-p->weight)
				vl[k]=vl[j]-p->weight; // 更新vl[k]
			p=p->nextarc;
		}
	}


	int z=0;
	cout<<"遍历关键路径"<<endl;
	for(i=0; i<G.vexnum; i++) { // 求各活动的最早，最晚发生事件，判断关键活动
		ArcNode *p=G.vertices[i].firstarc; // p指向第i个顶点的第一个弧结点
		while(p!=NULL) {
			j=p->adjvex; // 依次取得i的邻接点j
			
			int e=ve[i];     // 计算活动<vi,vj>的最早开始时间
			ed[z]=ve[i];	 // 活动最早开始时间 

			int l=vl[j]-p->weight;
			ld[z]=vl[j]-p->weight;
			// 活动最迟开始时间 
			z++;

			if(e==l)
				cout<<G.vertices[i].data<<" "<<G.vertices[j].data<<" "<<endl;
			p=p->nextarc; // 继续下一个活动
		}
	}
	cout<<endl;
	cout<<"顶点的发生时间"<<endl; 
	cout<<"顶点i\t|ve(i)\t|vl(i)"<<endl;
	for(i=0; i<G.vexnum; i++) {
		cout<<i<<"\t|"<<ve[i]<<"\t|"<<vl[i]<<endl;
	}
	cout<<endl;
	cout<<"活动的开始时间"<<endl; 
	cout<<"活动ai\te(i)\tl(i)\tl(i)-e(i)"<<endl;
	for(i=0; i<G.arcnum; i++) {
		cout<<"a"<<i<<"\t|"<<ed[i]<<"\t|"<<ld[i]<<"\t|"<<ld[i]-ed[i]<<endl;
	}
	return true;
}

int main() {
	cout<<"AOE（Activity on Edge）代码测试"<<endl;

	// 建立一个图
	ALGraph G;

	// 创建有向网
	CreateDN(G);

	//  初始化拓扑数组
	int topo[G.vexnum];

	cout<<endl;
	// 遍历邻接表和逆邻接表
	TraverseGraphList(G);
	cout<<endl;

	// AOV 拓扑排序来查看当前图是否有环
	bool flag=TopologicalSort(G,topo);

	cout<<endl;
	// 遍历topo数组
	cout<<"topo数组：";
	for(int i=0; i<G.vexnum; i++)
		cout<<topo[i]<<" ";
	cout<<endl<<endl;


	// 关键路径
	CriticalPath(G);
}
