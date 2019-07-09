#include<iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 20     //˳�����󳤶�

typedef struct {
	int key;           //�ؼ�����ؼ�������Ϊ����
	char *otherinfo;   //����������
} RedType;    //��¼����

typedef struct {
	RedType r[MAXSIZE+1];     //0�ŵ�Ԫ����
	int length;               //˳�����
} SqList;    //˳�������


//��˳���L�еļ�¼����ֱ�Ӳ�������
void InsertSort(SqList &L) {
	for(int i=2; i<=L.length; i++) {       		 // ����L.length-1������
		if(L.r[i].key<L.r[i-1].key) { 			 // ��L.r[i]���������ӱ�
			L.r[0]=L.r[i];
			int j;					     // ��������ļ�¼�ݴ浽��������
			for(j=i-1; L.r[0].key<L.r[j].key; j--) // �Ӻ���ǰѰ�Ҳ���λ��
				L.r[j+1]=L.r[j];  				 // ��¼����ƶ�
			L.r[j+1]=L.r[0]; 					 // ���뵽��ȷλ��
		}
	}
}

//��˳���L�еļ�¼�����۰��������
void BInsertSort(SqList &L) {
	for(int i=2; i<=L.length; i++) {
		L.r[0]=L.r[i]; 					// ��L.r[i]�ݴ浽L.r[0]
		int low=1,high=i-1;
		while(low<=high) { 				// ��r[low..high]���۰���Ҳ���λ��
			int m=(low+high)/2;
			if(L.r[0].key<L.r[m].key)
				high=m-1;   			// ������ڵͰ���
			else
				low=m+1;				// ������ڸ߰���
		}
		for(int j=i-1; j>=high+1; --j)
			L.r[j+1]=L.r[j];			// ��¼����
		L.r[high+1]=L.r[0];				// ����
	}
}

//��˳���L�еļ�¼����һ������Ϊdk��ϣ������
void ShellInsert(SqList &L,int dk) {
	//�벹��ò���
	for(int i=dk+1; i<=L.length; i++) {
		if(L.r[i].key<L.r[i-dk].key) { // ��L.r[i]���������ӱ�
			L.r[0]=L.r[i];            // ��L.r[0]�ݴ�������¼L.r[i]
			int j;
			for(j=i-dk; j>0&&L.r[0].key<L.r[j].key; j-=dk)
				L.r[j+dk]=L.r[j];     // ��¼����
			L.r[j+dk]=L.r[0];		  // ������ȷ��λ��
		}
	}
}

//��˳���L�еļ�¼���������У��洢������dt�У�����t��ϣ������
void ShellSort(SqList &L,int dt[],int t) {
	//�벹��ò���
	for(int k=0; k<t; k++)
		ShellInsert(L,dt[k]);
	// һ������Ϊdt[k]��ϣ����������
}

//��˳���L�еļ�¼����ð������
void BubbleSort(SqList &L) {
	//�벹��ò���
	int flag=1,j;
	for(int i=L.length-1; i>=1&&flag; i--) { // ������������
		flag=0; // ÿ������ʼʱ����flag
		for(j=1; j<=i; j++) { // ��ǰ���ɨ�豾��������[1...i+1]
			if(L.r[j].key>L.r[j+1].key) { // �����ڼ�¼�����򣬽���֮
				flag=1;			// ���������з����˽�������flag��Ϊ1
				RedType t=L.r[j];
				L.r[j]=L.r[j+1];
				L.r[j+1]=t;
			}
		}
	}
}

//��˳���L�е��ӱ�L.r[low...high]����һ�λ��֣�����������λ��
int Partition(SqList &L,int low,int high) {
	// ��˳���L��[low..high]����һ�˿������򣬲����������¼
	// ����λ�ã�ʹ������֮ǰ�ļ�¼�Ĺؼ��־����������Ĺؼ���
	// ������֮��ļ�¼�Ĺؼ��־���С�����Ĺؼ���
	L.r[0]=L.r[low];      // �������¼������������÷���
	int pivotkey=L.r[low].key;// �����¼�ؼ���
	while(low<high) {  	 // �ӱ�����˽�������м�ɨ��
		while(low<high&&L.r[high].key>=pivotkey)
			--high;
		L.r[low]=L.r[high]; // ���������¼С�ļ�¼�Ƶ��Ͷ�
		while(low<high&&L.r[low].key<=pivotkey)
			++low;
		L.r[high]=L.r[low]; // ���������¼��ļ�¼�Ƶ��ߴ�
	}
	L.r[low]=L.r[0]; // ���������¼��ļ�¼�ƶ����߶�
	return low;
}


//��˳���L�е�������L.r[low...high]���п�������
void QSort(SqList &L,int low,int high) {
	//�벹��ò���
	if(low<high) { // ���ȴ���1
		int pivotloc=Partition(L,low,high);
		// ��L.r[row...high]һ��Ϊ����pivotlocΪ����λ��
		QSort(L,low,pivotloc-1); // ���������еݹ�����
		QSort(L,pivotloc+1,high); // ���������еݹ�����
	}
}

//��˳���L�еļ�¼���п�������
void QuickSort(SqList &L) {
	//�벹��ò���
	QSort(L,1,L.length);
}

//��˳���L�еļ�¼���м�ѡ������
void SelectSort(SqList &L) {
	//�벹��ò���
	for(int i=1; i<L.length; i++) { // ��������
		// ��L.r
		int k=i;
		for(int j=i+1; j<=L.length; j++) {
			if(L.r[j].key<L.r[k].key)
				k=j;
		}
		if(i!=k) {
			RedType t=L.r[i];
			L.r[i]=L.r[k];
			L.r[k]=t;
		} // ����L.r[i]��L.r[k]
	} // for i
}

//�ѵĵ���������L.r[s+1...m]�Ѿ���һ������ѣ��ò�����L.r[s...m]����Ϊ��L.r[s]Ϊ���Ĵ����
void HeapAdjust(SqList &L,int s,int m) {
	//�벹��ò���
	//����r[s+1..m]�Ѿ��Ƕѣ���r[s..m]����Ϊ��r[s]Ϊ���Ĵ����
	RedType rc;
	int j;
	rc=L.r[s];
	for(j=2*s; j<=m; j*=2) {
		//��key�ϴ�ĺ��ӽ������ɸѡ
		if(j<m&&L.r[j].key<L.r[j+1].key) ++j;		//jΪkey�ϴ�ļ�¼���±�
		if(rc.key>=L.r[j].key) break;      			//rcӦ������λ��s��
		L.r[s]=L.r[j];
		s=j;
	}
	L.r[s]=rc;

}

//��˳���L�е������¼���н��ɴ����
void CreatHeap(SqList &L) {
	//�벹��ò���
	int i,n;
	n=L.length;
	for(i=n/2; i>0; i--)
		HeapAdjust(L,i,n);
}

//��˳���L�еļ�¼���ж�����
void HeapSort(SqList &L) {
	//�벹��ò���
	//��˳���L���ж�����
	int i;
	RedType x;
	CreatHeap(L);              					//����������L.r[1..L.length]���ɴ����
	for(i=L.length; i>1; --i) {
		x=L.r[1];               				//���Ѷ���¼�͵�ǰδ������������L.r[1..i]�����һ����¼����
		L.r[1]=L.r[i];
		L.r[i]=x;
		HeapAdjust(L,1,i-1);					//��L.r[1..i-1]���µ���Ϊ�����
	}//for
}

//�������R[low...mid]��R[mid+1...high]�鲢Ϊ�����T[low...high]
void Merge(RedType R[],RedType T[],int low,int mid,int high) {
	//�벹��ò���
	int i=low,j=mid+1,k=low;
	while(i<=mid&&j<=high) {
		if(R[i].key<R[j].key)
			T[k++]=R[i++];
		else
			T[k++]=R[j++];
	}
	while(i<=mid)
		T[k++]=R[i++];
	while(j<=high)
		T[k++]=R[j++];
}

//��R[low...high]�еļ�¼�鲢��������T[low...high]��
void MSort(RedType R[],RedType T[],int low,int high) {
	//�벹��ò���
	RedType *S=new RedType[MAXSIZE];
	if(low==high)
		T[low]=R[low];
	else {
		int mid=(low+high)/2;
		MSort(R,S,low,mid);
		MSort(R,S,mid+1,high);
		Merge(S,T,low,mid,high);
	}
}

//��˳���L�еļ�¼���й鲢����
void MergeSort(SqList &L) {
	//�벹��ò���
	MSort(L.r,L.r,1,L.length);
}
//����˳�����˳���L�����10����¼����¼�Ĺؼ���Ϊ1-100��Χ�ڵ��������
void CreateList(SqList &L) {
	int i;
	srand(time(0));
	for(i=1; i<=10; i++) {
		L.r[i].key =rand()%100+1;
	}
	L.length =10;
}

//���˳���L�и���¼�ؼ��ֵ�ֵ���м��ÿո�ָ�
void PrintList(SqList L) {
	int i;
	for(i=1; i<=L.length ; i++) {
		cout<<L.r[i].key <<"  ";
	}
	cout<<endl;
}

//����˵�
void showmenu() {
	cout<<endl;
	cout<<"*************���򷽷�************************"<<endl;
	cout<<"1. ֱ�Ӳ�������\t2. �۰��������"<<endl;
	cout<<"3. ϣ������\t4. ð������"<<endl;
	cout<<"5. ��������\t6. ��ѡ������"<<endl;
	cout<<"7. ������\t8. ��·�鲢����"<<endl;
	cout<<"0.�˳�"<<endl;
	cout<<"��ѡ��Ҫִ�е����򷽷����"<<endl;

}

int main() {
	SqList L;
	int n,dt[3]= {5,3,1};   //dt�д�ŵ���ϣ������ʱʹ�õ���������
	CreateList(L);         //��������Ϊ10��˳���L�����м�¼�Ĺؼ���Ϊ1-100��Χ�ڵ��������
	showmenu();
	cin>>n;         //���ѡ������򷽷����
	while(n!=0) {   //ѭ����ʾ�˵�����0��������
		if(n>=1&&n<=8) {
			cout<<"�������¼��ʼ�ؼ���Ϊ��"<<endl;
			PrintList(L);        //�������ǰ���и���¼�ؼ��ֵ�ֵ
		}
		switch(n) {   //����ѡ�����ŵ��ò�ͬ�����򷽷�
			case 1:
				cout<<"ֱ�Ӳ�������Ľ��Ϊ��"<<endl;
				InsertSort(L);    //ֱ�Ӳ�������
				PrintList(L);     //�����������¼�ؼ��ֵ�ֵ
				break;
			case 2:
				cout<<"�۰��������Ľ��Ϊ��"<<endl;
				BInsertSort(L);   //�۰��������
				PrintList(L);
				break;
			case 3:
				cout<<"ϣ������Ľ��Ϊ��"<<endl;
				ShellSort(L,dt,3);    //ϣ�����򣬣�3�ˣ�
				PrintList(L);
				break;
			case 4:
				cout<<"ð������Ľ��Ϊ��"<<endl;
				BubbleSort(L);     //ð������
				PrintList(L);
				break;
			case 5:
				cout<<"��������Ľ��Ϊ��"<<endl;
				QuickSort(L);    //��������
				PrintList(L);
				break;
			case 6:
				cout<<"��ѡ������Ľ��Ϊ��"<<endl;
				SelectSort(L);     //��ѡ������
				PrintList(L);
				break;
			case 7:
				cout<<"������Ľ��Ϊ��"<<endl;
				HeapSort(L);    //������
				PrintList(L);
				break;
			case 8:
				cout<<"��������Ľ��Ϊ��"<<endl;
				MergeSort(L);    //��·�鲢����
				PrintList(L);
				break;
			default:
				cout<<"���ѡ�����������ѡ��"<<endl;
				break;

		}
		CreateList(L);    //ÿ�����������L�е�10����¼
		showmenu();
		cin>>n;
		system("cls");   //����
	}
}
