#include<iostream>
#include<memory.h>

using namespace std;

// void* memset(void*,int,unsigned)
// 其中void*表示地址
// 它可以一字节一字节地把整个数组设置为指定的值 
// 参数1：数组的起始地址
// 参数2：数字每个字节的值
// 参数3：数组所占的字节数 

int main(){
	int ia1[50];
	int ia2[500];
	memset(ia1,0,50*sizeof(int));
	memset(ia2,0,500*sizeof(int));
	
	for(int i=0;i<50;i++){
		cout<<ia1[i]<<" ";
	} 
	
} 
