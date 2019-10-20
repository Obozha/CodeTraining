#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//-----图的邻接矩阵存储表示-----
#define MaxInt 32767		// 表示极大值，即∞ 
#define MVNum 100			// 最大顶点数 
#define OK 1

typedef int Status;
typedef char VerTexType;	// 假设顶点的数据类型为字符型
typedef int ArcType;		// 假设边的权值类型为整形
typedef struct {
	VerTexType vexs[MVNum];	// 顶点表
	ArcType arcs[MVNum][MVNum]; // 邻接矩阵
	int vexnum,arcnum;			// 图的当前点数和边数
} AMGraph;

/* method：LocateVex
 * description：存在则返回u在顶点表中的下标；否则返回-1
 * param：
 *		ALGraph G  图的结构体
 *		VerTexType u 顶点的值
 * return： int 返回顶点下标，没有就返回-1
 */
int LocateVex(AMGraph G,VerTexType u) {
	// 存在则返回u在顶点表中的下标；否则返回-1
	int i;
	for(i=0; i<G.vexnum; i++)
		if(u==G.vexs[i]) {
			return i;
		}
	return -1;
}

typedef int VRType;
struct{
	VerTexType adjvex; // 该边所依附的在U中的顶点
	VRType lowcost; // 该边的权值
} closedge[MVNum];
int Min(AMGraph G) {
	// 返回权值最小的点
	int i;
	int index=-1;
	int min=MaxInt;
	for(i=0; i<G.vexnum; i++) {
		if(min>closedge[i].lowcost&&closedge[i].lowcost!=0) {
			min=closedge[i].lowcost;
			index=i;
		}
	} // for
	return index;
}

void MainSpanTree_Prim(AMGraph G,VerTexType u) {
	// 用prim算法从第u个顶点出发构造网G的最小生成树
	int i,j,k=LocateVex(G,u);
	for(j=1; j<G.vexnum; j++)
		if(j!=k)
			closedge[j]= {u,G.arcs[k][j]};
	cout<<"初始化结果"<<endl;
	closedge[k].lowcost=0; // U={u},初始化集合U
	closedge[k].adjvex='a';
	cout<<"adjvex:\t"<<"lowcost:\t"<<endl;
	for(j=0; j<G.vexnum; j++) {
		if(closedge[j].lowcost==MaxInt) {
			cout<<closedge[j].adjvex<<"\t"<<"∞"<<"\t"<<endl;
		} else {
			cout<<closedge[j].adjvex<<"\t"<<closedge[j].lowcost<<"\t"<<endl;
		}
	}
	for(i=1; i<G.vexnum; i++) {
		k=Min(G); // 求出生成树的下一个结点，第k个顶点
		cout<<"当前的k值:"<<k<<endl; 
		cout<<closedge[k].adjvex<<G.vexs[k]<<endl; // 输出生成树的边
		closedge[k].lowcost=0; // 第k个顶点并入U
		for(j=0; j<G.vexnum; j++) { // 重新调整侯选边
			if(G.arcs[k][j]<closedge[j].lowcost) {
				closedge[j]= {G.vexs[k],G.arcs[k][j]};
			}
		}
		for(j=0; j<G.vexnum; j++) {
			if(closedge[j].lowcost==MaxInt) {
				cout<<closedge[j].adjvex<<"\t"<<"∞"<<"\t"<<endl;
			} else {
				cout<<closedge[j].adjvex<<"\t"<<closedge[j].lowcost<<"\t"<<endl;
			}
		}
		cout<<"u{";
		for(j=0; j<G.vexnum; j++) {
			if(closedge[j].lowcost==0)
				cout<<G.vexs[j];
		}
		cout<<"}"<<endl;
		
	}// for
	
//	for(j=0;i<G.vexnum;j++){
//		cout<<
//	}
	 
} // MiniSpanTree_PRIM

int main() {
	AMGraph G,GN,temp {
		{1,2,3,4,5,6},
		{
			{0,0,0,0,0,0,0},
			{0,0,1,1,1,0,0},
			{0,1,0,0,0,1,0},
			{0,1,0,0,0,1,0},
			{0,1,0,0,0,0,1},
			{0,0,1,1,0,0,0},
			{0,0,0,0,1,0,0}
		},6,6
	},temp2 {
		{'a','b','c','d','e','f'},
		{
			{MaxInt,12,MaxInt,MaxInt,9,9},
			{12,MaxInt,6,MaxInt,MaxInt,15},
			{MaxInt,6,MaxInt,3,MaxInt,17},
			{MaxInt,MaxInt,3,MaxInt,4,20},
			{9,MaxInt,MaxInt,4,MaxInt,9},
			{9,15,17,MaxInt,9,MaxInt}
		},6,10
	};

	MainSpanTree_Prim(temp2,'a');
}
