#include<stdio.h>
float *search(float (*pointer)[4]);
int main(){
	float score[][4]={
		{60,70,80,90},
		{56,89,67,88},
		{34,78,90,66}		// 定义数组，存放成绩 
	};
	
	float *p;
	int i,j;
	for(i=0;i<3;i++){
		p=search(score+i);	 	// 调用search函数，如果有不及格返回score[i][0]，否则返回空 
		if(p==*(score+i)){ 		// 如果返回的是score[i][0]的地址，表示p的值不是NULL 
			printf("No.%d score:",i);
			for(j=0;j<4;j++)
				printf("%5.2f ",*(p+j));	// 输出score[i][0]~score[i][3]
			printf("\n"); 
		}
		
	}
	return 0;
}

float *search(float (*pointer)[4]){ // 定义函数，形参pointer是指向一维数组的指针变量 
	int i=0;
	float *pt;
	pt=NULL;
	for(;i<4;i++)
		if(*(*pointer+i)<60)
			pt=*pointer;
	return pt;
}
