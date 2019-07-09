#include<stdio.h>

// 实参用数组名a，形参可用数组名
// 也可用指针变量名


 
void inv(int *x,int n); // inv函数声明 

int main(){
	int i,a[10]={0,1,2,3,4,5,6,7,8,9};
	printf("The original array:\n");
	for(i=0;i<10;i++){
		printf("%d ",a[i]);		// 输出未交换时数组各元素的值 
	}
	printf("\n");
	inv(a,10);					// 调用inv函数 进行交换 
	printf("The array has been inverted:\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);		// 输出交换后各数组元素的值 
	printf("\n");
	return 0;
}

void inv(int x[],int n){ // 形参x是参数名 
	int temp,i,j,m=n/2;
	for(i=0;i<m;i++){
		j=n-1-i;
		temp=x[i];
		x[i]=x[j];
		x[j]=temp;		// 把x[i]和x[j]交换 
	}
}
