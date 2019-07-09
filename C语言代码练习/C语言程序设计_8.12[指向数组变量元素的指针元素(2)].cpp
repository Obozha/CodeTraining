#include<stdio.h>
/*
	解题思路:假设仍然用例8.12程序中的二维数组
	例8.12中定义的指针变量是指向变量(或数组变量) 
	现在改用指向一维数组的指针变量 
*/

int main(){
	int a[3][4] = {1,3,5,7,9,11,13,15,17,19,21,23};		// 定义二维数组a并初始化
	int (*p)[4],i,j;		// 指针变量p指向包含4个整形元素的一维数组 
	p=a;					// p指向二维数组的0行 
	printf("please enter row and colum:");	
	scanf("%d %d",&i,&j);	// 输入要求输出的元素的序列号 
	if(i<3&&j<4){
		printf("a[%d,%d]=%d\n",i,j,*(*(p+i)+j));	// 输出a[i][j] 
	}else{
		printf("输入错误 超出指针范围");
	}
	return 0; 
}
