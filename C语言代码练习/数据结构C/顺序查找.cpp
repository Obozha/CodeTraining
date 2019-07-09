#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MAXSIZE 100
#define OK 1
#define ERROR -1

typedef int Status;
typedef struct {
	int key; // 关键字域 
}ElemType;

typedef struct {
	ElemType *R;
	int length;
}SSTable; // static search table

/*
 * 初始化静态搜素表，向内存中申请空间 
 */
Status InitList_SSTable(SSTable &L){
	//L.R=new ElemType[MAXSIZE];
	L.R=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	if(!L.R){
		cout<<"初始化错误"<<endl;
		return ERROR;
	}
	L.length=0;
	return OK;
}

/*
 * 插入搜索表的数据  
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
 * 顺序查找 
 */
Status Search_Seq(SSTable ST,int key){
	// 在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，
	// 函数值为该元素在表中的位置，否则为0
	for(int i=ST.length;i>=1;--i)
		if(ST.R[i].key==key)
			return i; 
	return 0;
}

void Show_End(int result,int testkey){
	if(result==0){
		cout<<"未找到"<<testkey<<endl;
	}else{
		cout<<"找到"<<testkey<<"位置为"<<result<<endl; 
	}
}

int main(){
	SSTable ST;
	
	// 初始化 
	InitList_SSTable(ST);
	
	// 插入数据 
	Insert_SSTable(ST);
	
	// 写出测试数据 
	int testkey1=50,testkey2=200;
	
	// 搜索后查看结果 
	Show_End(Search_Seq(ST,testkey1),testkey1);
	Show_End(Search_Seq(ST,testkey2),testkey2);
}
