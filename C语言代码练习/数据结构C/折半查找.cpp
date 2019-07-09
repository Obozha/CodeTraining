#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MAXSIZE 10
#define OK 1
#define ERROR -1

typedef int Status;
typedef struct {
	int key; // 关键字域 
}ElemType;

typedef struct{
	ElemType *R;
	int length;
}SSTable;

/* method：InitList_SSTable
 * description：初始化顺序表 / 静态表
 * param：
 *		@SSTable &L 传入一个顺序表结构体指针
 * return： Status 返回一个状态值 OK 1 /ERROR -1
 */ 
Status InitList_SSTable(SSTable &L){
	L.R=new ElemType[MAXSIZE];
	if(!L.R){
		cout<<"初始化错误";
		return 0;
	}
	L.length=0;
	return OK;
}

/* method：Insert_SSTable
 * description：插入顺序表数据 
 * param：
 *		@SSTable &L 传入一个顺序表结构体指针 
 * return： Status 返回一个状态值 OK 1 /ERROR -1
 */ 
Status Insert_SSTable(SSTable &L){
	for(int i=1,j=1;i<MAXSIZE;i++,j++){
		L.R[i].key=j;
		L.length++;
	}
	return OK;
}

/* method：Search_Bin
 * description：搜索顺序表 
 * param：
 *		@SSTable &L 传入一个顺序表结构体指针   
 *  	@int key 查找关键字 
 * return： int 返回搜索位置 
 */ 
int Search_Bin(SSTable ST,int key){
	// 在有序表ST中折半查找其关键字等于key的数据元素，若找到 
	// 则函数值为该元素在表中的位置，否则为0
	int low=1,high=ST.length,mid; 
	while(low<=high){
		mid=(low+high)/2;
		if(key==ST.R[mid].key)
			return mid;
		else if(key<ST.R[mid].key)
			high=mid-1;
		else
			low=mid+1;		
	} 
	return 0;
} 

/* method：Show_End
 * description：显示结果 
 * param：
 *		@int result  根据搜索结果来显示输出字符串 
 *  	@int testkey 查找关键字 
 * return：void 
 */ 
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
	
	// 准备测试数据 
	int testkey1=5,testkey2=10;
	
	// 搜索后查看结果 
	Show_End(Search_Bin(ST,testkey1),testkey1);
	Show_End(Search_Bin(ST,testkey2),testkey2);
}
