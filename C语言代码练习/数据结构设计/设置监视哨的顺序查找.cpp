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
	int key; // 关键字域 
}ElemType;

typedef struct{
	ElemType *R;
	int length;
}SSTable;

Status InitList_SSTable(SSTable &L){
	// 申请空间	
	L.R=new ElemType[MAXSIZE];
//	L.R=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	
	// 判断申请是否成功 
	if(!L.R){
		cout<<"初始化错误";
		return 0;
	} 
	
	// 初始化长度 
	L.length=0;
	return OK;
}

Status Insert_SSTable(SSTable &L){
	for(int i=1,j=1;i<MAXSIZE;i++,j++){ // 空出ST.R[0]的位置 
		L.R[i].key=j;
		L.length++;
	}
	return OK;
}

Position Search_Seq(SSTable ST,int key){
	// 在顺序表ST中顺序查找其关键字等于key的数据元素。若找到
	// 返回该元素在表中的位置，否则为0
	ST.R[0].key=key;
	int i;
	for(i=ST.length;ST.R[i].key!=key;--i);
	return i;
} // Search_Seq

void Show_End(int result,int testkey){
	if(result==0)
		cout<<"未找到"<<testkey<<endl;
	else
		cout<<"找到"<<testkey<<"位置为"<<result<<endl; 
}

int main(){
	SSTable ST;
	
	// 初始化 
	InitList_SSTable(ST);
	
	// 插入数据 
	Insert_SSTable(ST);
	
	// 写出测试数据 
	int testkey1=5,testkey2=200;
	
	// 搜索后查看结果 
	Show_End(Search_Seq(ST,testkey1),testkey1);
	Show_End(Search_Seq(ST,testkey2),testkey2);
}
