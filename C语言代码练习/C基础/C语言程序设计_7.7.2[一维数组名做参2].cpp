#include<stdio.h>

float getAvg(float array[10]);
int getLength(float a[]);


int main(){
	float score[10],aver;
	int i;
	
	printf("请输入成绩[10个] 按Enter键发送...:");
	for(i=0;i<10;i++)
		scanf("%f",&score[i]);
	printf("\n");
	
	aver = getAvg(score);
	printf("平均成绩为：%5.2f\n",aver);
	printf("数组长度为:%d",getLength(score));
	
	return 0;
} 

float getAvg(float array[10]){ // 定义average函数 
	int i;
	float aver,sum=0;
	for(i=0;i<10;i++)
		sum+=array[i];   // 累加学生成绩 
	aver = sum/10;
	return aver;
	
}

int getLength(float a[]){
	int length;
	length=sizeof(a)/sizeof(a[0]);
	return length;	
}

// 因为 a是函数参数 到了本函数 a只是一个指针
// (地址 系统在本函数运行时候 是不知道a所表示的地址有多大
// 的储存空间，这里只是告诉函数:一个数据存储空间首地址）
// 所以 sizeof(a)的结果是指针变量a占内存的大小 
// 




