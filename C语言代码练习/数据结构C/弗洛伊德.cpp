#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MaxInt 32767		// 表示极大值，即∞
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;

typedef struct{
	VerTexType vexs[MVNum];      // 顶点表
	ArcType arcs[MVNum][MVNum]; // 邻接矩阵
	int vexnum,arcnum; 			// 图的当前点数和边数 
}AMGraph;

/* method：LocateVex
 * description：存在则返回u在顶点表中的下标；否则返回-1
 * param：
 *		ALGraph G  图的结构体
 *		VerTexType u 顶点的值 
 * return： int 返回顶点下标，没有就返回-1 
 */
int LocateVex(AMGraph G,VerTexType u){
	// 存在则返回u在顶点表的下标，否则返回-1
	int i;
	for(i=0;i<G.vexnum;i++)
		if(u==G.vexs[i])
			return i;
	return -1; 
}

/* method：CreateDN
 * description：创建有向网 
 * param：
 *		AMGraph &G    图结构体引用 
 * return： bool 成功返回true 
 */
void CreateDN(AMGraph &G){
	// 采用邻接矩阵表示法，创建无向网G
	int i,j,k;
	cout<<"请输入总定点数，总边数，以空格隔开：";
	cin>>G.vexnum>>G.arcnum;
	cout<<"请输入点的名称：";
	for(i=0;i<G.vexnum;i++){
		cin>>G.vexs[i];
	}
	cout<<endl;
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=MaxInt;
	cout<<"输入边依附的顶点及权值:"<<endl;
	for(k=0;k<G.arcnum;k++){
		VerTexType v1,v2;
		ArcType w;
		cin>>v1>>v2>>w;
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		G.arcs[i][j]=w;
	}
}

/* method：ShortestPath_Floyd
 * description：弗洛伊德算各个顶点的距离 
 * param：
 *		AMGraph G    图结构体
 * return： void
 */
void ShortestPath_Floyd(AMGraph G){
	// 用Floyd算法求有向网G中对顶点i和j之间的最短路径Path[i][j]及其带权
	// 路径长度D[i][j]
	int i,j,k,D[G.vexnum][G.vexnum],Path[G.vexnum][G.vexnum]; 
	for(i=0;i<G.vexnum;i++){ // 初始化各对顶点之间的路径及距离 
		for(j=0;j<G.vexnum;j++){
			D[i][j]=G.arcs[i][j];
			if(D[i][j]<MaxInt) // 从i到j有直接路径
				Path[i][j]=i;	// 将j的前驱置为i
			else
				Path[i][j]=-1;	// 将j的前驱置为i	 
		}
	}
	for(k=0;k<G.vexnum;k++) // 在顶点i和j之间加入顶点逐步试探
		for(i=0;i<G.vexnum;i++)
			for(j=0;j<G.vexnum;j++)
				if(D[i][k]+D[k][j]<D[i][j] && i!=j){
					D[i][j]=D[i][k]+D[k][j];
					Path[i][j]=Path[k][j]; 
				}else if(i==j){
					D[i][j]=0;
				}
				// 从i经k到j的一条路径更短
				// 更改j的前驱为k O(n3) 
	for(i=0;i<G.vexnum;i++){
		for(j=0;j<G.vexnum;j++){
			cout<<D[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(i=0;i<G.vexnum;i++){
		for(j=0;j<G.vexnum;j++){
			cout<<Path[i][j]<<" ";
		}
		cout<<endl;
	}
} 

int main(){
	cout<<"最短路径算法Floyd代码测试"<<endl;
	
	AMGraph G;
	
	// 创建图 
	CreateDN(G);
	
	// 弗洛伊德算法 
	ShortestPath_Floyd(G);
}
