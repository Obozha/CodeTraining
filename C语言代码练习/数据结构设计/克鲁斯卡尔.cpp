#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MaxInt 32767		// 表示极大值，即∞
#define MVNum 100
#define OK 1
typedef int Status;
typedef int OtherInfo;
typedef int VerTexType;
typedef int ArcType;


typedef struct {
	VerTexType vexs[MVNum];	// 顶点表
	ArcType arcs[MVNum][MVNum]; // 邻接矩阵
	int vexnum,arcnum;			// 图的当前点数和边数
} AMGraph;

struct {
	VerTexType head; // 边的起点
	VerTexType tail; // 边的终点
	int lowcost;     // 边的权值
} Edge[10];

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

/* method：CreateUDG
 * description：采用邻接矩阵表示法，创建无向网
 * param：
 *		ALGraph &G  图的结构体引用
 * return： void
 */
void CreateUDN(AMGraph &G) {
	// 采用邻接矩阵表示法，创建无向网G
	int i,j,k;
	cout<<"请输入总定点数，总边数，以空格隔开：";
	cin>>G.vexnum>>G.arcnum;
	cout<<"请输入点的名称:";
	for(i=0; i<G.vexnum; i++) {
		cin>>G.vexs[i];
	}
	cout<<endl;
	for(i=0; i<G.vexnum; i++)
		for(j=0; j<G.vexnum; j++)
			G.arcs[i][j]=MaxInt;
	cout<<"输入边依附的顶点及权值:"<<endl;
	for(k=0; k<G.arcnum; k++) {
		VerTexType v1,v2;
		ArcType w;
		cin>>v1>>v2>>w;
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		G.arcs[i][j]=w;
		G.arcs[j][i]=G.arcs[i][j];
		Edge[k].lowcost=w;
		Edge[k].head=v1;
		Edge[k].tail=v2;
	}
}

/* method：Sort
 * description：冒泡排序 
 * param：
 *		ALGraph G  图的结构体
 * return： void
 */
void Sort(AMGraph G) {
	cout<<"===============================冒泡排序过程===============================" <<endl;
	int m=G.arcnum-2,j;
	int flag=1;
	while((m>0)&&flag==1) {
		flag=0;
		cout<<m<<":"<<"j\thead\ttail\tlowcost"<<endl;
		for(j=0; j<G.arcnum; j++) {
			cout<<j<<"\t"<<Edge[j].head<<"\t"<<Edge[j].tail<<"\t"
			    <<Edge[j].lowcost<<endl;
		}
		for(j=0; j<=m; j++) {
			if(Edge[j].lowcost>Edge[j+1].lowcost) {
				flag=1;
				VerTexType temp_Head=Edge[j].head;
				Edge[j].head=Edge[j+1].head;
				Edge[j+1].head=temp_Head;

				VerTexType temp_Tail=Edge[j].tail;
				Edge[j].tail=Edge[j+1].tail;
				Edge[j+1].tail=temp_Tail;

				ArcType temp_lowcost=Edge[j].lowcost;
				Edge[j].lowcost=Edge[j+1].lowcost;
				Edge[j+1].lowcost=temp_lowcost;
			}
		}
		m--;
	}
	cout<<"完成"<<endl<<"j\thead\ttail\tlowcost"<<endl;
	for(j=0; j<G.arcnum; j++) {
		cout<<j<<"\t"<<Edge[j].head<<"\t"<<Edge[j].tail<<"\t"
		    <<Edge[j].lowcost<<endl;
	}
	cout<<"===============================冒泡排序过程===============================" <<endl;
}

/* method：MiniSpanTree_kruskal
 * description：克鲁斯卡尔算法，排序算出Edge，然后按照权值从小到大选择边，出现Vexset连通分量相同的舍弃 
 * param：
 *		ALGraph G  图的结构体
 * return： void
 */
void MiniSpanTree_kruskal(AMGraph G) {
	Sort(G);  // 将边按权值由小到大排序
	int count=0,i,j;  //  计数器，当count=n-1时，算法结束
	int Vexset[G.arcnum];
	for(i=0; i<G.arcnum; i++)
		Vexset[i]=i; // 为每个顶点的连通分量赋初值
	for(i=0; i<G.arcnum; i++) { // 依次处理Edge中的边
		int v1=LocateVex(G,Edge[i].head);  // 获取最小边
		int v2=LocateVex(G,Edge[i].tail);
		int vs1=Vexset[v1];
		int vs2=Vexset[v2];
		if(vs1!=vs2) { // 两个顶点不在同一个连通分量中
			cout<<Edge[i].head<<"  "<<Edge[i].tail<<endl; // 输出边
			for(j=0; j<G.vexnum; j++) { // 合并vs1和vs2两个分量
				if(Vexset[j]==vs2)
					Vexset[j]=vs1;
			}
			count++;
			if(count==G.vexnum-1)
				break;
			cout<<"当前Vexset数组:";
			for(j=0; j<G.vexnum; j++) {
				cout<<Vexset[j]<<" ";
			}
		}

		cout<<endl;
	}
	cout<<"当前Vexset数组:";
	for(j=0; j<G.vexnum; j++) {
		cout<<Vexset[j]<<" ";
	}
}

int main() {
	
	AMGraph G;
	
	// 创建无向图 
	CreateUDN(G);
	
	// 创建最小生成树 
	MiniSpanTree_kruskal(G);
}
