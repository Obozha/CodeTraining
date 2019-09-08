#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

using namespace std;
#define MaxInt 32767		// 表示极大值，即∞
#define MVNum 100
typedef int VerTexType;
typedef int ArcType;

typedef struct {
	VerTexType vexs[MVNum];	// 顶点表
	ArcType arcs[MVNum][MVNum]; // 邻接矩阵
	int vexnum,arcnum;			// 图的当前点数和边数
} AMGraph;

/* method：InitStack
 * description：存在则返回u在顶点表的下标，否则返回-1
 * param：
 *		AMGraph G    图结构体
 *	 	VerTexType u 顶点 
 * return： int 返回顶点下标，否则返回-1 
 */
int LocateVex(AMGraph G,VerTexType u){
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
bool CreateDN(AMGraph &G){
	// 采用邻接矩阵表示法，创建无向网G
	int i,j,k,w;
	VerTexType v1,v2;
	cout<<"请输入总顶点数，总边数：";
	cin>>G.vexnum>>G.arcnum;
	cout<<"请输入顶点数据";
	for(i=0;i<G.vexnum;i++)
		cin>>G.vexs[i];
	cout<<endl;
	cout<<"初始化网络..."<<endl;
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=MaxInt;
	cout<<"初始化成功..."<<endl;
	cout<<"请输入一条边依附在两个顶点和权值"<<endl;
	for(k=0;k<G.arcnum;k++){
		cin>>v1>>v2>>w;
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		// 确认v1和v2在G中的位置，即顶点数组的下标
		G.arcs[i][j]=w;
		// 依附顶点 
	}
	return true;
}

/* method：ShortestPath_DIJ 
 * description：最短路径 迪杰斯特拉算法 
 * param：
 *		AMGraph G    图结构体
 *		VerTexType v0		 需要求的某一点 
 * return： bool 成功返回true 
 */
void ShortestPath_DIJ(AMGraph G,VerTexType v0) {
	int D[MVNum],Path[MVNum],i,v,w,min;  //数组D存储源点到其它顶点的最短路径长度,Path数组存放每个顶点的前驱顶点
	bool S[MVNum];    //每个顶点是否已求得最短路径的标志存放在数组S中
	char *str,*temp;
	
	str=(char*)malloc(sizeof(char)*100);
	temp=(char*)malloc(sizeof(char)*100);
	
	//初始化三个数组
	for(v=0; v<G.vexnum ; v++) {
		//请同学们在此处根据注释，补充该循环
		S[v]=false; 		// v相当于算法中的vk 
		D[v]=G.arcs[v0][v]; //  
		if(D[v]<MaxInt)
			Path[v]=v0;
		else
			Path[v]=-1;
	}
	//将第v0个顶点设置为源点
	S[v0]=true;
	D[v0]=0;
	//循环G.vexnum-1次,求第v0个顶点到图中其它顶点的最短距离
	for(i=1; i<G.vexnum ; i++) {
		//寻找距离源点最近的第v个顶点
		//请同学们在此处根据注释，补充该操作
		min=MaxInt;
		//更新源点到其它顶点的最短距离
		for(w=0; w<G.vexnum ; w++) {
			//请同学们在此处根据注释，补充该循环
			if(!S[w]&&D[w]<min){
				v=w;
				min=D[w];
			} // w顶点离v0更近 
		}//for(w)
		S[v]=true;      //将第v个顶点加入到S中，S表示已求得最短路径的顶点集合
		for(w=0;w<G.vexnum;w++){
			if(!S[w]&&(D[v]+G.arcs[v][w]<D[w])){
				D[w]=D[v]+G.arcs[v][w];
				Path[w]=v;
			}
		}
	}//for(i)
	strcpy(str," ");
	//输出源点到其它顶点的最短路径及路径长度
	for(i=0; i<G.vexnum; i++) {
		int j=i;
		int k;
		while(j!=-1){
			strcat(str,itoa(j,temp,10));
			j=Path[j];
		}
		strcat(str,"\0");
		if(D[i]==MaxInt){
			cout<<"顶点"<<G.vexs [v0]<<"到顶点"<<G.vexs [i]<<"的最短路径长度为∞"<<",路径为：";
		}else{
			cout<<"顶点"<<G.vexs [v0]<<"到顶点"<<G.vexs [i]<<"的最短路径长度为"<<D[i]<<",路径为：";
		}
		
		for(k=strlen(str)-1;k>=0;k--){
			if(D[i]==0){
				cout<<"源点和源点自成回路";
				break;
			}else if(D[i]==MaxInt){
				cout<<"不可到达";
				break;
			}
			if(k==0){
				cout<<"v"<<str[k];
			}else{
				cout<<"v"<<str[k]<<" -> ";
			}
			
		}
		cout<<endl;
		//从第i个顶点回溯，输出第i个顶点到源点的最短路径
		//请同学们在此处根据注释，补充该操作，输出源点到其它顶点的最短路径
		strcpy(str,"");
	}
	free(str);
	free(temp);
}

int main(){
	cout<<"最短路径算法Dijkstra代码测试"<<endl;
	AMGraph G;
	
	// 创建图 
	CreateDN(G);

	// 求得最短路径 
	ShortestPath_DIJ(G,0);
} 
