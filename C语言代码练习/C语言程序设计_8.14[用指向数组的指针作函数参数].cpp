#include<stdio.h>

void average(float*,int);
void search(float (*p)[4],int n);

int main(){
	float score[3][4]={{65,67,70,60},{80,87,90,81},{90,99,100,98}};
	average(*score,12);		// 求12个分数的平均分
	search(score,2); 		// 求序号为2的学生的成绩 
	return 0; 
}

void average(float *p,int n){ // 定义求平均成绩的函数 
	float *p_end;
	float sum=0,aver;
	p_end=p+n;				// n的值为12时候，p_end值指向p+12 p+11其实就是末尾了 
	for(;p<p_end;p++)		// 当p_end 指向p+12 就退出循环 也就是P+11是最后一个 
		sum=sum+(*p);
	aver=sum/n;
	printf("average =%5.2f \n",aver);
}

void search(float (*p)[4],int n){	//p是指向具有4个元素的一维数组的指针 
	int i;
	printf("The score of No.%d are:\n",n);
	for(i=0;i<4;i++)
		printf("%5.2f ",*(*(p+n)+i));
	printf("\n");
}
