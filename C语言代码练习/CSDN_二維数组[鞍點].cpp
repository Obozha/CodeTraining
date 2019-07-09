#include<stdio.h>

int main() {
	// 读入一个数字，决定这个方形矩阵是几阶的
	int n;
	scanf("%d",&n);

	// 定义n阶矩阵以及将要用到的变量
	int matrix[n][n];
	int i,j,temp,count,flag=0;

	// 读入矩阵中的每一个数
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			scanf("%d",&temp);
			matrix[i][j]=temp;
		}
	}

	// 测试读入的数据是否正确
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}

	// 开始寻找鞍点
	for(i=0; i<n; i++) {
		// 找出每行中的最大的数字
		temp=matrix[i][0]; // 用temp与count标识出每行最大的数字和位置
		count=0;

		for(j=1; j<n; j++) {
			if(temp<matrix[i][j]) {
				temp=matrix[i][j];
				count=j;
			}
		}
		// 测试一下，此行最大的数字，是否是所在列的最小数字
		for(j=0; j<n; j++) {
			if(matrix[j][count]<temp) {
				flag++;// 如果有数字小temp,flag就不为0
			}
		}

		if(flag==0) { // 测试flag值，如果为0，证明此数正是要找的鞍点
			printf("%d %d\n",i,count);
			break;
		}
		flag=0;
	}

	if(i==n){
		printf("No");
	} 
	return 0;
}
