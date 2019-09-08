#include<stdio.h>

float *search(float (*pointer)[4],int); 
int main() {
	float score[][4]={{60,70,80,90},{56,89,67,88},{34,78,90,66}}; // 定义数组，存放成绩
	float *p;
	int i,k;
	printf("enter the number of student:");
	scanf("%d",&k);
	printf("The scores of No.%d are:\n",k);
	p=search(score,k);
	for(i=0;i<4;i++){
		printf("%5.2f\t",*(p+i));
	}
	printf("\n");
	return 0;
}

float *search(float (*pointer)[4],int n){ // 形参pointer是指向一维数组的指针变量 
	float *pt;
	pt=*(pointer+n);		// pt的值是&score[k][0] 
	return pt;
}
