#include<stdio.h>

void inv(int*,int);

int main(){
	int i,a[10]={3,7,9,11,0,6,7,5,4,2};
	printf("The original array:\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	inv(a,10);
	printf("The array has been inverted:\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}

void inv(int *x,int n){	// 形参x是指针变量 
	int*p,temp,*i,*j,m=(n-1)/2;
	i=x; // 将首地址赋给i i指针在数组开头 
	j=x+n-1; // j地址在 首地址+9 j指针在数组末尾 
	p=x+m; // p为首地址+4 p指针在数组中间 
	for(;i<=p;i++,j--){
		temp=*i;
		*i=*j;
		*j=temp;		// *i与*j交换 
	}
} 
