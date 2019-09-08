#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
//-----ͼ���ڽӾ���洢��ʾ-----
#define MaxInt 32767		// ��ʾ����ֵ������ 
#define MVNum 100			// ��󶥵��� 
#define OK 1

typedef int Status;
typedef char VerTexType;	// ���趥�����������Ϊ�ַ���
typedef int ArcType;		// ����ߵ�Ȩֵ����Ϊ����
typedef struct {
	VerTexType vexs[MVNum];	// �����
	ArcType arcs[MVNum][MVNum]; // �ڽӾ���
	int vexnum,arcnum;			// ͼ�ĵ�ǰ�����ͱ���
} AMGraph;

int LocateVex(AMGraph G,VerTexType u) {
	// �����򷵻�u�ڶ�����е��±ꣻ���򷵻�-1
	int i;
	for(i=0; i<G.vexnum; i++)
		if(u==G.vexs[i]) {
			return i;
		}
	return -1;
}

Status CreateUDN(AMGraph &G) {
	// �����ڽӾ����ʾ��������������G
	int i,j,k,w;
	VerTexType v1,v2;
	printf("�������ܶ��������ܱ���:");
	scanf("%d %d",&G.vexnum,&G.arcnum);
	printf("�����붥�����ݣ�");
	for(i=1; i<=G.vexnum; i++) {
		scanf("%c",&G.vexs[i]);
	}
	printf("\n");
	printf("��ʼ������ ...\n");
	for(i=1; i<=G.vexnum; i++)
		for(j=1; j<=G.vexnum; j++)
			G.arcs[i][j]=MaxInt;
	printf("��ʼ���ɹ� ...\n");
	for(k=1; k<=G.arcnum; k++) {
		printf("������һ�������������������Ȩֵ:");
		scanf("%d %d %d",&v1,&v2,&w);
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		// ȷ��v1��v2��G�е�λ�ã�������������±�
		G.arcs[i][j]=w;
		G.arcs[j][i]=G.arcs[i][j];
		// ��������
	}
	return OK;
}

typedef int VRType;
struct u{
	VerTexType adjvex; // �ñ�����������U�еĶ���
	VRType lowcost; // �ñߵ�Ȩֵ
} closedge[MVNum];
int Min(AMGraph G) {
	// ����Ȩֵ��С�ĵ�
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
	// ��prim�㷨�ӵ�u���������������G����С������
	int i,j,k=LocateVex(G,u);
	for(j=1; j<G.vexnum; j++)
		if(j!=k)
			closedge[j]= {u,G.arcs[k][j]};
	cout<<"��ʼ�����"<<endl;
	closedge[k].lowcost=0; // U={u},��ʼ������U
	closedge[k].adjvex='a';
	cout<<"adjvex:\t"<<"lowcost:\t"<<endl;
	for(j=0; j<G.vexnum; j++) {
		if(closedge[j].lowcost==MaxInt) {
			cout<<closedge[j].adjvex<<"\t"<<"��"<<"\t"<<endl;
		} else {
			cout<<closedge[j].adjvex<<"\t"<<closedge[j].lowcost<<"\t"<<endl;
		}
	}
	for(i=1; i<G.vexnum; i++) {
		k=Min(G); // �������������һ����㣬��k������
		cout<<"��ǰ��kֵ:"<<k<<endl; 
		cout<<closedge[k].adjvex<<G.vexs[k]<<endl; // ����������ı�
		closedge[k].lowcost=0; // ��k�����㲢��U
		for(j=0; j<G.vexnum; j++) { // ���µ�����ѡ��
			if(G.arcs[k][j]<closedge[j].lowcost) {
				closedge[j]= {G.vexs[k],G.arcs[k][j]};
			}
		}
		for(j=0; j<G.vexnum; j++) {
			if(closedge[j].lowcost==MaxInt) {
				cout<<closedge[j].adjvex<<"\t"<<"��"<<"\t"<<endl;
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



Status CreateUDG(AMGraph &G) {
	// �����ڽӾ����ʾ������������ͼG
	int i,j,k;
	VerTexType v1,v2;
	printf("�������ܶ��������ܱ���:");
	scanf("%d %d",&G.vexnum,&G.arcnum);
	printf("�����붥�����ݣ�");
	for(i=1; i<=G.vexnum; i++) {
		scanf("%c",&G.vexs[i]);
	}
	printf("\n");
	printf("��ʼ��ͼ ...\n");
	for(i=1; i<=G.vexnum; i++)
		for(j=1; j<=G.vexnum; j++)
			G.arcs[i][j]=0;
	printf("��ʼ���ɹ� ...\n");
	for(k=1; k<=G.arcnum; k++) {
		printf("������һ������������������:");
		scanf("%d %d",&v1,&v2);
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		// ȷ��v1��v2��G�е�λ�ã�������������±�
		G.arcs[i][j]=1;
		G.arcs[j][i]=1;
		// ��������
	}
	return OK;
}

void PrintMatrix(AMGraph G) {
	int i,j;
	for(i=1; i<=G.vexnum; i++) {
		for(j=1; j<=G.vexnum; j++) {
			if(G.arcs[i][j]!=MaxInt) {
				printf("%d\t",G.arcs[i][j]);
			} else {
				printf("��\t");
			}
		}
		printf("\n");
	}
	printf("\n");
}

bool visited[MVNum];
void DFS(AMGraph G,int v) {
	// ͼGΪ�ڽӾ�������
	int w;
	printf("%d ",v);
	visited[v]=true; // ���ʵ�v������
	for(w=1; w<=G.vexnum; w++) // ���μ���ڽӾ���v���ڵ���
		if((G.arcs[v][w]!=0)&&(!visited[w]))
			DFS(G,w);
	// w��v���ڽӵ㣬���wδ���ʣ���ݹ����DFS
}

int main() {
	AMGraph G;
//	,GN,temp {
//		{1,2,3,4,5,6},
//		{
//			{0,0,0,0,0,0,0},
//			{0,0,1,1,1,0,0},
//			{0,1,0,0,0,1,0},
//			{0,1,0,0,0,1,0},
//			{0,1,0,0,0,0,1},
//			{0,0,1,1,0,0,0},
//			{0,0,0,0,1,0,0}
//		},6,6
//	},temp2 {
//		{'a','b','c','d','e','f'},
//		{
//			{MaxInt,12,MaxInt,MaxInt,9,9},
//			{12,MaxInt,6,MaxInt,MaxInt,15},
//			{MaxInt,6,MaxInt,3,MaxInt,17},
//			{MaxInt,MaxInt,3,MaxInt,4,20},
//			{9,MaxInt,MaxInt,4,MaxInt,9},
//			{9,15,17,MaxInt,9,MaxInt}
//		},6,10
//	};
//
//	MainSpanTree_Prim(temp2,'a');


//	printf("��ʼ����ͼ\n");
	if(CreateUDG(G)==OK){
		printf("ͼ�����ɹ�\n");
	}
//	PrintMatrix(temp);
	PrintMatrix(G);
//	printf("\n");
//	printf("��ʼ������\n");
//	if(CreateUDN(GN)==OK){
//		printf("�������ɹ�\n");
//	}
//	PrintMatrix(GN);

}
