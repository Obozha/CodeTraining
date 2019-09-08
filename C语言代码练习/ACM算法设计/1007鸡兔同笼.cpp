#include<stdio.h>

int main(){
	int m,n; // 定义m和n，存储头的个数和脚的只数 
	int x,y; // 定义x和y，分别储存鸡和兔子的数量 
	scanf("%d %d",&m,&n);
	y=(n-2*m)/2; // 解方程计算出兔子的个数y
	x=m-y; // 计算出鸡的个数x
	printf("%d %d\n",x,y);
	return 0; 
}
