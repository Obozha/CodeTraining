#include<stdio.h>
#include<stdlib.h> 

// 回调函数

void populate_array(int *array,size_t arraySize,int (*getNextValue)(void)){
	for(size_t i=0;i<arraySize;i++)
		array[i]=getNextValue();
} 

// 获取随机值
int getNextRandomValue(void){
	return rand();
}

int main(void){
	int myarray[10]; 
	populate_array(myarray,10,&getNextRandomValue);
	// 通过回调 传入myarray的地址，sizet型值，传入getNextRandomValue的方法地址 
	
	
	for(int i=0;i<10;i++)
		printf("%d ",myarray[i]);
	printf("\n");
	printf(" %d",sizeof(size_t));
	
	
	return 0;
}

// 有关于 size_t
// size_t是一种数据类型，近似于无符号整形，但范围容量一般大于int和unsigned。
// 这里使用size_t是为了保证arraysize变量能够有足够大的容量来储存可能大的数值

//  
