#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MAXSIZE 100
#define OK 1
#define ERROR -1

typedef int Status;
typedef struct {
	int key; // �ؼ����� 
}ElemType;

typedef struct {
	ElemType *R;
	int length;
}SSTable; // static search table

/*
 * ��ʼ����̬���ر����ڴ�������ռ� 
 */
Status InitList_SSTable(SSTable &L){
	//L.R=new ElemType[MAXSIZE];
	L.R=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	if(!L.R){
		cout<<"��ʼ������"<<endl;
		return ERROR;
	}
	L.length=0;
	return OK;
}

/*
 * ���������������  
 */
Status Insert_SSTable(SSTable &L){
	int j=0;
	for(int i=0,j=0;i<MAXSIZE;i++,j++){
		L.R[i].key=j;
		L.length++;
	}
	return OK;
}

/*
 * ˳����� 
 */
Status Search_Seq(SSTable ST,int key){
	// ��˳���ST��˳�������ؼ��ֵ���key������Ԫ�ء����ҵ���
	// ����ֵΪ��Ԫ���ڱ��е�λ�ã�����Ϊ0
	for(int i=ST.length;i>=1;--i)
		if(ST.R[i].key==key)
			return i; 
	return 0;
}

void Show_End(int result,int testkey){
	if(result==0){
		cout<<"δ�ҵ�"<<testkey<<endl;
	}else{
		cout<<"�ҵ�"<<testkey<<"λ��Ϊ"<<result<<endl; 
	}
}

int main(){
	SSTable ST;
	
	// ��ʼ�� 
	InitList_SSTable(ST);
	
	// �������� 
	Insert_SSTable(ST);
	
	// д���������� 
	int testkey1=50,testkey2=200;
	
	// ������鿴��� 
	Show_End(Search_Seq(ST,testkey1),testkey1);
	Show_End(Search_Seq(ST,testkey2),testkey2);
}
