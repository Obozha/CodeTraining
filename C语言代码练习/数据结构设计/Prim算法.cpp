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

/* method��LocateVex
 * description�������򷵻�u�ڶ�����е��±ꣻ���򷵻�-1
 * param��
 *		ALGraph G  ͼ�Ľṹ��
 *		VerTexType u �����ֵ
 * return�� int ���ض����±꣬û�оͷ���-1
 */
int LocateVex(AMGraph G,VerTexType u) {
	// �����򷵻�u�ڶ�����е��±ꣻ���򷵻�-1
	int i;
	for(i=0; i<G.vexnum; i++)
		if(u==G.vexs[i]) {
			return i;
		}
	return -1;
}

typedef int VRType;
struct{
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
