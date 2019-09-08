#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MAXSIZE 10
#define OK 1
#define ERROR -1

typedef int Status;
typedef int Position;
typedef struct {
	int key; // �ؼ����� 
}ElemType;

typedef struct{
	ElemType *R;
	int length;
}SSTable;

Status InitList_SSTable(SSTable &L){
	// ����ռ�	
	L.R=new ElemType[MAXSIZE];
//	L.R=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	
	// �ж������Ƿ�ɹ� 
	if(!L.R){
		cout<<"��ʼ������";
		return 0;
	} 
	
	// ��ʼ������ 
	L.length=0;
	return OK;
}

Status Insert_SSTable(SSTable &L){
	for(int i=1,j=1;i<MAXSIZE;i++,j++){ // �ճ�ST.R[0]��λ�� 
		L.R[i].key=j;
		L.length++;
	}
	return OK;
}

Position Search_Seq(SSTable ST,int key){
	// ��˳���ST��˳�������ؼ��ֵ���key������Ԫ�ء����ҵ�
	// ���ظ�Ԫ���ڱ��е�λ�ã�����Ϊ0
	ST.R[0].key=key;
	int i;
	for(i=ST.length;ST.R[i].key!=key;--i);
	return i;
} // Search_Seq

void Show_End(int result,int testkey){
	if(result==0)
		cout<<"δ�ҵ�"<<testkey<<endl;
	else
		cout<<"�ҵ�"<<testkey<<"λ��Ϊ"<<result<<endl; 
}

int main(){
	SSTable ST;
	
	// ��ʼ�� 
	InitList_SSTable(ST);
	
	// �������� 
	Insert_SSTable(ST);
	
	// д���������� 
	int testkey1=5,testkey2=200;
	
	// ������鿴��� 
	Show_End(Search_Seq(ST,testkey1),testkey1);
	Show_End(Search_Seq(ST,testkey2),testkey2);
}
