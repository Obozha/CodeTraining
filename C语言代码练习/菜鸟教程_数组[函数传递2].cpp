#include<stdio.h>

double getAvg(int arr[],int size){
	int sum=0;
	int i;
	double avg;
	
	for(i=0;i<size;i++)
		sum+=arr[i];
	 
	 avg=sum/size;
	 return avg;
}

/* 函数声明 */
double getAvg(int[],int);

int main(){
	/* 带有5个元素的整形数组 */
	int balance[5]={1000,2,3,17,50};
	double avg;
	
	/* 传递一个指向数组的指针作为参数 */
	avg=getAvg(balance,5);
	/* 输出返回值 */
	printf("平均值是%1.1f",avg);
	return 0; 
}
