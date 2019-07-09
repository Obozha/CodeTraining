#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define MaxInt 32767    //Ȩֵ�����ֵ
#define MVNum 100       //��󶥵���


//�ڽӾ���洢�ṹ����
typedef struct {
	char vexs[MVNum];         //��Ŷ��������
	int arcs[MVNum][MVNum];    //����ڽӾ��������
	int vexnum,arcnum;         //�������ͱߣ�������
} AMGraph;

//�ߣ��������ṹ����
typedef struct ArcNode {
	int adjvex;
	struct ArcNode *nextarc;
	int weight;
} ArcNode;

//�������Ͷ���
typedef struct VNode {
	char data;
	ArcNode *firstarc;
} VNode,AdjList[MVNum];   //�����������Ͷ���

//�ڽӱ�ṹ����
typedef struct {
	AdjList vertices;    //��������
	int vexnum,arcnum;   //�������ͱߣ�������
} ALGraph;

//˳����нṹ����
typedef struct {
	int front;      //��ͷ
	int rear;       //��β
	char base[MVNum];   //��Ŷ���Ԫ�ص�����
} SqQueue;

bool visited[MVNum];   //���ͼ�ж�����ʱ�־������

//��ʼ������
void InitQueue(SqQueue &Q) {
	Q.front =Q.rear =0;
}

//�ж϶���Q�Ƿ�Ϊ�գ�Ϊ�շ���true���ǿշ���false
bool QueueEmpty(SqQueue Q) {
	if(Q.rear ==Q.front )
		return true;
	else
		return false;
}

//��Ӳ�������n����˳�����Q��β��
void EnQueue(SqQueue &Q,int n) {
	if(Q.rear -Q.front ==MVNum)  //����ʱ������ִ����Ӳ���
		exit(-1);
	else {
		Q.base [Q.rear ]=n;
		Q.rear ++;
	}
}

//���Ӳ�����ɾ������Q�Ķ�ͷԪ�أ���ɾԪ����n����
void DeQueue(SqQueue &Q,int &n) {
	if(QueueEmpty(Q))     //������Ϊ�գ�����ִ�г��Ӳ���
		exit(-1);
	else {
		n=Q.base [Q.front  ];
		Q.front ++;
	}
}

//�����ڽӱ�ʽ�洢��ͼG�У�����ֵΪch�Ķ����λ��
int LocateVex(ALGraph G,char ch) {
	//��ͬѧ���ڴ˴�����ò���
	int i;
	for(i=0; i<G.vexnum; i++) {
		if(ch==G.vertices[i].data) {
			return i;
		}
	}

	return 0;//���벹�����������޸Ĵ��д��룬����ֵΪch�Ķ����λ��
}

//���ڽӱ�Ϊ�洢�ṹ����������ͼG
void CreateUDG_AL(ALGraph &G) {
	//��ͬѧ���ڴ˴����������ò���
	int i,j,k;
	char v1,v2;
	cout<<"�������ܶ��������ܱ���:";
	cin>>G.vexnum>>G.arcnum;
	cout<<"�����붥������:"; 
	for(i=0;i<G.vexnum;i++){
		cin>>G.vertices[i].data;	 // ���붥������ 
		G.vertices[i].firstarc=NULL; // ��ʼ��ͷ����ָ����ΪNULL 
	}
	cout<<"������ÿ������������������";
	for(k=0;k<G.arcnum;k++){
		cin>>v1>>v2;
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		// ȷ��v1��v2��G��λ�ã���������G.vertices
		
		ArcNode* p1=(ArcNode*)malloc(sizeof(ArcNode));
		p1->adjvex=j;
		p1->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;
		
		ArcNode *p2=(ArcNode*)malloc(sizeof(ArcNode));
		p2->adjvex=i;
		p2->nextarc=G.vertices[i].firstarc;
		G.vertices[j].firstarc=p2;
	}	
	
	
}

//�����ڽӾ���ʽ�洢��ͼG�У�����ֵΪch�Ķ����λ��
int LocateVex1(AMGraph G,char ch) {
	//��ͬѧ���ڴ˴�����ò���
	int i;
	for(i=0;i<G.vexnum;i++)
		if(ch==G.vexs[i]){
			return i;
		}
	return -1;//���벹�����������޸Ĵ��д��룬����ֵΪch�Ķ����λ��
}

//���ڽӾ���Ϊ�洢�ṹ����������ͼG
void CreateDG_AM(AMGraph &G) {
	int i,j,k;
	char v1,v2;
	cout<<"�������ܶ��������ܱ���:";
	cin>>G.vexnum>>G.arcnum;
	cout<<"�����붥������:";
	for(i=1;i<=G.vexnum;i++){
		cin>>G.vexs[i];
	}
	cout<<endl<<"��ʼ��ͼ ..."<<endl;
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=0;
	cout<<"��ʼ���ɹ� ...\n";
	for(k=0;k<G.arcnum;k++){
		cout<<"������һ���������������㣺";
		cin>>v1>>v2;
		i=LocateVex1(G,v1);
		j=LocateVex1(G,v2);
		G.arcs[i][j]=1;	
		// �������� 
	}
}	

bool visited_AL[MVNum];
//��ͼ�еĵ�v�������������ȱ���ͼG�����ڽӱ�Ϊ�洢�ṹ��
void DFS(ALGraph G,int v) {
	//��ͬѧ���ڴ˴�����ò���
	cout<<G.vertices[v].data<<" ";				// ���ʵ�v�����㣬 
	visited[v]=true;
	ArcNode *p=G.vertices[v].firstarc;
	while(p){
		if(!visited[p->adjvex])
			DFS(G,p->adjvex);
		p=p->nextarc;
	}
}

//��ȱ���ͼG
void DFSTraverse(ALGraph G) {
	int v;
	for(v=0; v<G.vexnum ; v++) //��ʼ�����ж���ķ��ʱ�־λfalse
		visited[v]=false;
	for(v=0; v<G.vexnum ; v++) { //��һ���ÿ������ķ��ʱ�־����һ��δ�����ʹ��Ķ���vΪ�����㣬��ͼG������ȱ���
		if(visited[v]==false)
			DFS(G,v);
	}
}

//��ͼ�еĵ�v�������������ȱ���ͼG�����ڽӱ�Ϊ�洢�ṹ��
void BFS(ALGraph G,int v) {
	SqQueue Q;      //QΪ˳�����
	ArcNode *p;
	int w,u;
	InitQueue(Q);     //��ʼ������Q
	cout<<G.vertices [v].data<<" ";    //�����v������
	visited[v]=true;                   //���õ�v������ķ��ʱ�־
	EnQueue(Q,v);                      //����v���������
	while(!QueueEmpty(Q)) {
		//��ͬѧ���ڴ˴�����ʣ�����
		DeQueue(Q,u);
		while(p){
			if(!visited[p->adjvex]){
				cout<<p->adjvex;
				visited[p->adjvex]=true;
				EnQueue(Q,w);				
			}
			p=p->nextarc;
		}
	}
}

//��ȱ���ͼG
void BFSTraverse(ALGraph G) {
	int v;
	for(v=0; v<G.vexnum ; v++)   //��ʼ�����ж���ķ��ʱ�־λfalse
		visited[v]=false;
	for(v=0; v<G.vexnum ; v++) { //��һ���ÿ������ķ��ʱ�־����һ��δ�����ʹ��Ķ���vΪ�����㣬��ͼG���й�ȱ���
		if(visited[v]==false)
			BFS(G,v);
	}
}


//                        ��������Ϊѡ���������·����������ɣ�
//*********************************************************************************************

//���ڽӾ���Ϊ�洢�ṹ������������G
void CreateDN_AM(AMGraph &G) {
	//��ͬѧ���ڴ˴�����ò���
	int i,j,k,w;
	char v1,v2;
	cout<<"�������ܶ��������ܱ���:";
	cin>>G.vexnum>>G.arcnum;
	cout<<"�����붥������:";
	for(i=0;i<G.vexnum;i++){
		cin>>G.vexs[i];
	}
	cout<<"��ʼ��ͼ"<<endl;
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=MaxInt;
	cout<<"��ʼ���ɹ� ..."<<endl;
	cout<<"����������������������Ȩֵ:";
	for(k=0;k<G.arcnum;k++){
		cin>>v1>>v2>>w;
		i=LocateVex1(G,v1);
		j=LocateVex1(G,v2);
		// ȷ��v1��v2��G�е�λ�ã�������������±� 
		G.arcs[i][j]=w;
	}
}

//ʹ�õϽ�˹�����㷨���v0�����㵽������������·��
void ShortestPath_DIJ(AMGraph G,int v0) {
	int D[MVNum],Path[MVNum],i,v,w,min;  //����D�洢Դ�㵽������������·������,Path������ÿ�������ǰ������
	bool S[MVNum];    //ÿ�������Ƿ���������·���ı�־���������S��
	char *str,*temp;
	
	str=(char*)malloc(sizeof(char)*100);
	temp=(char*)malloc(sizeof(char)*100);
	
	//��ʼ����������
	for(v=0; v<G.vexnum ; v++) {
		//��ͬѧ���ڴ˴�����ע�ͣ������ѭ��
		S[v]=false; 		// v�൱���㷨�е�vk 
		D[v]=G.arcs[v0][v]; //  
		if(D[v]<MaxInt)
			Path[v]=v0;
		else
			Path[v]=-1;
	}
	//����v0����������ΪԴ��
	S[v0]=true;
	D[v0]=0;
	//ѭ��G.vexnum-1��,���v0�����㵽ͼ�������������̾���
	for(i=1; i<G.vexnum ; i++) {
		//Ѱ�Ҿ���Դ������ĵ�v������
		//��ͬѧ���ڴ˴�����ע�ͣ�����ò���
		min=MaxInt;
		//����Դ�㵽�����������̾���
		for(w=0; w<G.vexnum ; w++) {
			//��ͬѧ���ڴ˴�����ע�ͣ������ѭ��
			if(!S[w]&&D[w]<min){
				v=w;
				min=D[w];
			} // w������v0���� 
		}//for(w)
		S[v]=true;      //����v��������뵽S�У�S��ʾ��������·���Ķ��㼯��
		for(w=0;w<G.vexnum;w++){
			if(!S[w]&&(D[v]+G.arcs[v][w]<D[w])){
				D[w]=D[v]+G.arcs[v][w];
				Path[w]=v;
			}
		}
	}//for(i)
	
	strcpy(str,"");
	//���Դ�㵽������������·����·������
	for(i=0; i<G.vexnum; i++) {
		int j=i;
		int k;
		while(j!=-1){
			strcat(str,itoa(j,temp,10));
			j=Path[j];
		}
		strcat(str,"\0");
		cout<<"����"<<G.vexs [v0]<<"������"<<G.vexs [i]<<"�����·������Ϊ"<<D[i]<<",·��Ϊ��";
		for(k=strlen(str)-1;k>=0;k--){
			if(D[i]==0){
				cout<<"Դ���Դ���Գɻ�·";
				break;
			}else if(D[i]==MaxInt){
				cout<<"���ɵ���";
				break;
			}
			if(k==0){
				cout<<"v"<<str[k];
			}else{
				cout<<"v"<<str[k]<<" -> ";
			}
			
		}
		cout<<endl;
		//�ӵ�i��������ݣ������i�����㵽Դ������·��
		//��ͬѧ���ڴ˴�����ע�ͣ�����ò��������Դ�㵽������������·��
		strcpy(str,"");
	}
}

// 1 2 1 3 2 4 2 5 3 6 3 7  5 8 4 8
// 1 2 3 4 5 6 7 8

int main() {
	ALGraph G;
	AMGraph G1;
	char ch;
	int k;
	//���²����������ͼG�Ĵ���(�����ڽӱ�洢��ʽ)��G����ȱ����͹�ȱ���
	cout<<"���²����������ͼG�Ĵ���(�����ڽӱ�洢��ʽ)��G����ȱ����͹�ȱ���"<<endl;
	CreateUDG_AL(G);     //��������ͼG
	cout<<"ͼG����ȱ�������Ϊ:";
	DFSTraverse(G);       //������ȱ���ͼG
	cout<<endl;
	cout<<"ͼG�Ĺ�ȱ�������Ϊ:";
	BFSTraverse(G);        //������ȱ���ͼG
	cout<<endl<<endl;

	//���²������������G1�Ĵ���(�����ڽӾ���洢��ʽ),����G1�������·��
	cout<<"****************************************************************************"<<endl;
	cout<<"���²������������G1�Ĵ���(�����ڽӾ���洢��ʽ),����G1�������·��"<<endl;
	CreateDN_AM(G1);    //����������G1
	cout<<"������Դ�㣺"<<endl;
	cin>>ch;                  //����Դ��
	k=LocateVex1(G1,ch);       //��Դ����G1�е�λ��k
	ShortestPath_DIJ(G1,k);    //ʹ�õϽ�˹�����㷨���k�����㵽������������·��
	return 0;
}
