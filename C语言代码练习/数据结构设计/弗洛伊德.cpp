#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MaxInt 32767		// ��ʾ����ֵ������
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;

typedef struct{
	VerTexType vexs[MVNum];      // �����
	ArcType arcs[MVNum][MVNum]; // �ڽӾ���
	int vexnum,arcnum; 			// ͼ�ĵ�ǰ�����ͱ��� 
}AMGraph;

/* method��LocateVex
 * description�������򷵻�u�ڶ�����е��±ꣻ���򷵻�-1
 * param��
 *		ALGraph G  ͼ�Ľṹ��
 *		VerTexType u �����ֵ 
 * return�� int ���ض����±꣬û�оͷ���-1 
 */
int LocateVex(AMGraph G,VerTexType u){
	// �����򷵻�u�ڶ������±꣬���򷵻�-1
	int i;
	for(i=0;i<G.vexnum;i++)
		if(u==G.vexs[i])
			return i;
	return -1; 
}

/* method��CreateDN
 * description������������ 
 * param��
 *		AMGraph &G    ͼ�ṹ������ 
 * return�� bool �ɹ�����true 
 */
void CreateDN(AMGraph &G){
	// �����ڽӾ����ʾ��������������G
	int i,j,k;
	cout<<"�������ܶ��������ܱ������Կո������";
	cin>>G.vexnum>>G.arcnum;
	cout<<"�����������ƣ�";
	for(i=0;i<G.vexnum;i++){
		cin>>G.vexs[i];
	}
	cout<<endl;
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=MaxInt;
	cout<<"����������Ķ��㼰Ȩֵ:"<<endl;
	for(k=0;k<G.arcnum;k++){
		VerTexType v1,v2;
		ArcType w;
		cin>>v1>>v2>>w;
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		G.arcs[i][j]=w;
	}
}

/* method��ShortestPath_Floyd
 * description�������������������ľ��� 
 * param��
 *		AMGraph G    ͼ�ṹ��
 * return�� void
 */
void ShortestPath_Floyd(AMGraph G){
	// ��Floyd�㷨��������G�жԶ���i��j֮������·��Path[i][j]�����Ȩ
	// ·������D[i][j]
	int i,j,k,D[G.vexnum][G.vexnum],Path[G.vexnum][G.vexnum]; 
	for(i=0;i<G.vexnum;i++){ // ��ʼ�����Զ���֮���·�������� 
		for(j=0;j<G.vexnum;j++){
			D[i][j]=G.arcs[i][j];
			if(D[i][j]<MaxInt) // ��i��j��ֱ��·��
				Path[i][j]=i;	// ��j��ǰ����Ϊi
			else
				Path[i][j]=-1;	// ��j��ǰ����Ϊi	 
		}
	}
	for(k=0;k<G.vexnum;k++) // �ڶ���i��j֮����붥������̽
		for(i=0;i<G.vexnum;i++)
			for(j=0;j<G.vexnum;j++)
				if(D[i][k]+D[k][j]<D[i][j] && i!=j){
					D[i][j]=D[i][k]+D[k][j];
					Path[i][j]=Path[k][j]; 
				}else if(i==j){
					D[i][j]=0;
				}
				// ��i��k��j��һ��·������
				// ����j��ǰ��Ϊk O(n3) 
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
	cout<<"���·���㷨Floyd�������"<<endl;
	
	AMGraph G;
	
	// ����ͼ 
	CreateDN(G);
	
	// ���������㷨 
	ShortestPath_Floyd(G);
}
