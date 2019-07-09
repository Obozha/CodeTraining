#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MAXSIZE 10
#define OK 1
#define ERROR -1

typedef int Status;
typedef struct {
	int key; // �ؼ����� 
}ElemType;

typedef struct{
	ElemType *R;
	int length;
}SSTable;

/* method��InitList_SSTable
 * description����ʼ��˳��� / ��̬��
 * param��
 *		@SSTable &L ����һ��˳���ṹ��ָ��
 * return�� Status ����һ��״ֵ̬ OK 1 /ERROR -1
 */ 
Status InitList_SSTable(SSTable &L){
	L.R=new ElemType[MAXSIZE];
	if(!L.R){
		cout<<"��ʼ������";
		return 0;
	}
	L.length=0;
	return OK;
}

/* method��Insert_SSTable
 * description������˳������� 
 * param��
 *		@SSTable &L ����һ��˳���ṹ��ָ�� 
 * return�� Status ����һ��״ֵ̬ OK 1 /ERROR -1
 */ 
Status Insert_SSTable(SSTable &L){
	for(int i=1,j=1;i<MAXSIZE;i++,j++){
		L.R[i].key=j;
		L.length++;
	}
	return OK;
}

/* method��Search_Bin
 * description������˳��� 
 * param��
 *		@SSTable &L ����һ��˳���ṹ��ָ��   
 *  	@int key ���ҹؼ��� 
 * return�� int ��������λ�� 
 */ 
int Search_Bin(SSTable ST,int key){
	// �������ST���۰������ؼ��ֵ���key������Ԫ�أ����ҵ� 
	// ����ֵΪ��Ԫ���ڱ��е�λ�ã�����Ϊ0
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

/* method��Show_End
 * description����ʾ��� 
 * param��
 *		@int result  ���������������ʾ����ַ��� 
 *  	@int testkey ���ҹؼ��� 
 * return��void 
 */ 
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
	
	// ׼���������� 
	int testkey1=5,testkey2=10;
	
	// ������鿴��� 
	Show_End(Search_Bin(ST,testkey1),testkey1);
	Show_End(Search_Bin(ST,testkey2),testkey2);
}
