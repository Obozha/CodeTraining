#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

using namespace std;
#define MaxInt 32767		// ��ʾ����ֵ������
#define MVNum 100
typedef int VerTexType;
typedef int ArcType;

typedef struct {
	VerTexType vexs[MVNum];	// �����
	ArcType arcs[MVNum][MVNum]; // �ڽӾ���
	int vexnum,arcnum;			// ͼ�ĵ�ǰ�����ͱ���
} AMGraph;

/* method��InitStack
 * description�������򷵻�u�ڶ������±꣬���򷵻�-1
 * param��
 *		AMGraph G    ͼ�ṹ��
 *	 	VerTexType u ���� 
 * return�� int ���ض����±꣬���򷵻�-1 
 */
int LocateVex(AMGraph G,VerTexType u){
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
bool CreateDN(AMGraph &G){
	// �����ڽӾ����ʾ��������������G
	int i,j,k,w;
	VerTexType v1,v2;
	cout<<"�������ܶ��������ܱ�����";
	cin>>G.vexnum>>G.arcnum;
	cout<<"�����붥������";
	for(i=0;i<G.vexnum;i++)
		cin>>G.vexs[i];
	cout<<endl;
	cout<<"��ʼ������..."<<endl;
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=MaxInt;
	cout<<"��ʼ���ɹ�..."<<endl;
	cout<<"������һ�������������������Ȩֵ"<<endl;
	for(k=0;k<G.arcnum;k++){
		cin>>v1>>v2>>w;
		i=LocateVex(G,v1);
		j=LocateVex(G,v2);
		// ȷ��v1��v2��G�е�λ�ã�������������±�
		G.arcs[i][j]=w;
		// �������� 
	}
	return true;
}

/* method��ShortestPath_DIJ 
 * description�����·�� �Ͻ�˹�����㷨 
 * param��
 *		AMGraph G    ͼ�ṹ��
 *		VerTexType v0		 ��Ҫ���ĳһ�� 
 * return�� bool �ɹ�����true 
 */
void ShortestPath_DIJ(AMGraph G,VerTexType v0) {
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
	strcpy(str," ");
	//���Դ�㵽������������·����·������
	for(i=0; i<G.vexnum; i++) {
		int j=i;
		int k;
		while(j!=-1){
			strcat(str,itoa(j,temp,10));
			j=Path[j];
		}
		strcat(str,"\0");
		if(D[i]==MaxInt){
			cout<<"����"<<G.vexs [v0]<<"������"<<G.vexs [i]<<"�����·������Ϊ��"<<",·��Ϊ��";
		}else{
			cout<<"����"<<G.vexs [v0]<<"������"<<G.vexs [i]<<"�����·������Ϊ"<<D[i]<<",·��Ϊ��";
		}
		
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
	free(str);
	free(temp);
}

int main(){
	cout<<"���·���㷨Dijkstra�������"<<endl;
	AMGraph G;
	
	// ����ͼ 
	CreateDN(G);

	// ������·�� 
	ShortestPath_DIJ(G,0);
} 
