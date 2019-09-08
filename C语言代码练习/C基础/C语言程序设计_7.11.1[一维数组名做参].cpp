#include<stdio.h>

float average(float array[],int n);

int main(){
	float score1[5] = {98.5,97,91.5,60,55}; // 定义长度为5的数组 
	float score2[10] = {67.5,89.5,99,69.5,77,89.5,76.5,54,60,99.5}; // 定义长度为10的数组
	printf("The average of class A is %6.2f\n",average(score1,5));
//	printf("The average of class B is %6.2f\n",average(score2,10));
	
}

float average(float array[],int n){
	
	printf("array大小:%d,真实的大小:%d\n",sizeof(array)/sizeof(array[0]),n);
	printf("sizeof(array):%d\n",sizeof(array));
	printf("sizeof(array[0]):%d\n",sizeof(array[0]));
	
	int i;
	float aver,sum=0;
	for(i=0;i<n;i++)
		sum+=array[i];
	aver=sum/n;
	return aver;
}
