#include<stdio.h>

int main(){
	int i,n;
	int preNum,curNum,temp;
	
	scanf("%d",&n);
	preNum=curNum=1;
	
	for(i=3;i<=n;i++){
		temp=curNum; // 暂存curNum
		curNum=curNum+preNum; // 计算新的一月兔子数量 
		preNum=temp; //  更新上一个月兔子数量 
	}
	printf("%d\n",curNum);
	return 0;
} 
