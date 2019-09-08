#include<stdio.h>

int main() {
	int i,j;
	int temp;
	int a[8]= {10,30,40,89,100,110,120};

	printf("输入一个插入的数字:");
	scanf("%d",&temp);
	
	for(i=6; i>=0; i--) { 
		if(a[i]>n) {
			a[i+1]=a[i]; // 比n大的数字向后移动位置 
		} else {
			break; // 发现跟n比，比n小就跳出 
		}
	}
	printf("当前位置：%d\n",i);
	a[i+1]=n; // 跳出的位置是比n小的位置i，n后边的位置i已经向后移动一个单位
	// 所以n要在数字i+1的位置 

	for(i=0; i<8; i++) {
		printf("%d ",a[i]);
	}
	// 输出 
}
