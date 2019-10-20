#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


#define MAXSIZE 7 // ˳�����󳤶�

typedef int KeyType; // ����ؼ�������
typedef int InfoType; 
typedef struct{
	KeyType key;			// �ؼ����� 
	InfoType otherinfo;		// ���������� 
}RedType;

typedef struct{
	RedType *r;  // r[0]���û����ڱ���Ԫ
	int length; 
}SqList;


void Merge(RedType R[],RedType T[],int low,int mid,int high){
	int i,j,k;
	i=low;j=mid+1;k=low;
	while(i<=mid&&j<=high){
		
		if(R[i].key<=R[j].key)
			T[k++]=R[i++];
		else
			T[k++]=R[j++];
	
	}
	while(i<=mid)
		T[k++]=R[i++];
	while(j<=high)
		T[k++]=R[j++]; 
}

RedType *S=new RedType[MAXSIZE];
void MSort(RedType R[],RedType T[],int low,int high){
	// R[low..high]�鲢��������T[low..high]��
	int mid;
	if(low==high) T[low]=R[low];
	else{
		mid=(low+high)/2; // ����ǰ����һ��Ϊ����������ѵ�mid
		MSort(R,S,low,mid);   // ��������R[low..mid]�ݹ�鲢���򣬽������S[low..mid] 
		MSort(R,S,mid+1,high);// ��������R[mid+1..high]�ݹ�鲢���򣬽������S[mid+1..high] 
		Merge(S,T,low,mid,high);	// ��S[low..mid]��S[mid+1..high]�鲢��T[low..high] 
	} 
} 

void MergeSort(SqList &L){
	MSort(L.r,L.r,1,L.length); 
}



int main(){
	SqList s;
	s.r=new RedType[MAXSIZE+1];
	s.length=MAXSIZE;
	for(int i=1;i<=MAXSIZE;i++){
//		srand((unsigned)time(NULL));
		s.r[i].key=rand() % 51 + 13;
		cout<<s.r[i].key<<" "; 
	}
	cout<<endl;
	MergeSort(s);

	for(int i=1;i<=s.length;i++){
		cout<<s.r[i].key<<" ";
	}
}
