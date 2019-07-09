#include<stdio.h>

/*
	解题思路 在主函数中定义二维数组score 定义search函数实现输出有一门以上课程
	不及格的学生的全部课程的成绩，形参p的类型是float(*)[4],p是指向包含4个元素的
	一维数组的指针变量。在调用search函数时，用score作为实参，它指向score[0]
	把score[0]的地址传给形参p 

*/ 

void search(float (*p)[4],int n);  // 函数声明 
int main(){
	float score[3][4]={ {65,57,70,60},{58,87,90,81},{90,99,100,98} }; // 定义二维数组函数score 
	search(score,3); // 调用 
	return 0;
} 

void search(float (*p)[4],int n){ // 形参p是指向包含4个float型的元素的一维变量 
	int i,j,flag;
	for(j=0;j<n;j++){
		flag=0;
		for(i=0;i<4;i++)
			if(*(*(p+j)+i)<60)
				flag=1;
		if(flag==1){
			printf("No.%d fails,his scores are:\n",j+1);
			for(i=0;i<4;i++) 
				printf("%5.1f ",*(*(p+j)+i));
			printf("\n");
		}
		
	}
}
