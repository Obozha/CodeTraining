#include<stdio.h>

int main(){
	int i,n;
	int preNum,curNum,temp;
	
	scanf("%d",&n);
	preNum=curNum=1;
	
	for(i=3;i<=n;i++){
		temp=curNum; // �ݴ�curNum
		curNum=curNum+preNum; // �����µ�һ���������� 
		preNum=temp; //  ������һ������������ 
	}
	printf("%d\n",curNum);
	return 0;
} 
