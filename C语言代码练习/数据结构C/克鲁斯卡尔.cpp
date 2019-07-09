#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MaxInt 32767		// ��ʾ����ֵ������
#define MVNum 100
#define OK 1
typedef int Status;
typedef int OtherInfo;
typedef int VerTexType;
typedef int ArcType;


typedef struct {
	VerTexType vexs[MVNum];	// �����
	ArcType arcs[MVNum][MVNum]; // �ڽӾ���
	int vexnum,arcnum;			// ͼ�ĵ�ǰ�����ͱ���
} AMGraph;

struct {
	VerTexType head; // �ߵ����
	VerTexType tail; // �ߵ��յ�
	int lowcost;     // �ߵ�Ȩֵ
} Edge[10];

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

/* method��CreateUDG
 * description�������ڽӾ����ʾ��������������
 * param��
 *		ALGraph &G  ͼ�Ľṹ������
 * return�� void
 */
void CreateUDN(AMGraph &G) {
	// �����ڽӾ����ʾ��������������G
	int i,j,k;
	cout<<"�������ܶ��������ܱ������Կո������";
	cin>>G.vexnum>>G.arcnum;
	cout<<"������������:";
	for(i=0; i<G.vexnum; i++) {
		cin>>G.vexs[i];
	}
	cout<<endl;
	for(i=0; i<G.vexnum; i++)
		for(j=0; j<G.vexnum; j++)
			G.arcs[i][j]=MaxInt;
	cout<<"����������Ķ��㼰Ȩֵ:"<<endl;
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

/* method��Sort
 * description��ð������ 
 * param��
 *		ALGraph G  ͼ�Ľṹ��
 * return�� void
 */
void Sort(AMGraph G) {
	cout<<"===============================ð���������===============================" <<endl;
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
	cout<<"���"<<endl<<"j\thead\ttail\tlowcost"<<endl;
	for(j=0; j<G.arcnum; j++) {
		cout<<j<<"\t"<<Edge[j].head<<"\t"<<Edge[j].tail<<"\t"
		    <<Edge[j].lowcost<<endl;
	}
	cout<<"===============================ð���������===============================" <<endl;
}

/* method��MiniSpanTree_kruskal
 * description����³˹�����㷨���������Edge��Ȼ����Ȩֵ��С����ѡ��ߣ�����Vexset��ͨ������ͬ������ 
 * param��
 *		ALGraph G  ͼ�Ľṹ��
 * return�� void
 */
void MiniSpanTree_kruskal(AMGraph G) {
	Sort(G);  // ���߰�Ȩֵ��С��������
	int count=0,i,j;  //  ����������count=n-1ʱ���㷨����
	int Vexset[G.arcnum];
	for(i=0; i<G.arcnum; i++)
		Vexset[i]=i; // Ϊÿ���������ͨ��������ֵ
	for(i=0; i<G.arcnum; i++) { // ���δ���Edge�еı�
		int v1=LocateVex(G,Edge[i].head);  // ��ȡ��С��
		int v2=LocateVex(G,Edge[i].tail);
		int vs1=Vexset[v1];
		int vs2=Vexset[v2];
		if(vs1!=vs2) { // �������㲻��ͬһ����ͨ������
			cout<<Edge[i].head<<"  "<<Edge[i].tail<<endl; // �����
			for(j=0; j<G.vexnum; j++) { // �ϲ�vs1��vs2��������
				if(Vexset[j]==vs2)
					Vexset[j]=vs1;
			}
			count++;
			if(count==G.vexnum-1)
				break;
			cout<<"��ǰVexset����:";
			for(j=0; j<G.vexnum; j++) {
				cout<<Vexset[j]<<" ";
			}
		}

		cout<<endl;
	}
	cout<<"��ǰVexset����:";
	for(j=0; j<G.vexnum; j++) {
		cout<<Vexset[j]<<" ";
	}
}

int main() {
	
	AMGraph G;
	
	// ��������ͼ 
	CreateUDN(G);
	
	// ������С������ 
	MiniSpanTree_kruskal(G);
}
