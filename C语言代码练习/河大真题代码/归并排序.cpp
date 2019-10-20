#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


#define MAXSIZE 7 // 顺序表最大长度

typedef int KeyType; // 定义关键字类型
typedef int InfoType; 
typedef struct{
	KeyType key;			// 关键字项 
	InfoType otherinfo;		// 其他数据项 
}RedType;

typedef struct{
	RedType *r;  // r[0]闲置或用哨兵单元
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
	// R[low..high]归并排序后放入T[low..high]中
	int mid;
	if(low==high) T[low]=R[low];
	else{
		mid=(low+high)/2; // 将当前序列一分为二，求出分裂点mid
		MSort(R,S,low,mid);   // 对子序列R[low..mid]递归归并排序，结果放入S[low..mid] 
		MSort(R,S,mid+1,high);// 对子序列R[mid+1..high]递归归并排序，结果放入S[mid+1..high] 
		Merge(S,T,low,mid,high);	// 将S[low..mid]和S[mid+1..high]归并到T[low..high] 
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
