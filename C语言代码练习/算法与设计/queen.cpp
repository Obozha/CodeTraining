#include<stdio.h>
#include<stdlib.h>
#
#define N 20
int q[N];
int count=0;

void dispasolution(int n){
	printf("   第%d个解  ",++count);
	for(int i=1;i<=n;i++){
		printf("(%d,%d)",i,q[i]);
	}
	printf("\n");
} 

bool place(int i,int j){
	if(i==1)
		return true;
	int k=1;
	while(k<i){
		if(q[k]==j||abs(q[k]-j)==abs(i-k))
			return false;
		k++;
	}
	return true;
}

// 1.设置断点
// 2.按Debug键 ---> 注意 如果代码修改之后 需要重新编译再Debug 
// 3.Next line 或者 into function 期间可以选中变量添加查看 Add watch 

// Next line 一行一行运行
// info function 进入函数语句内部的源代码 

void queen(int i,int n){
	if(i>n){
		dispasolution(n);
	}else{
		for(int j=1;j<=n;j++){
			if(place(i,j)){
				q[i]=j;
				queen(i+1,n);
			}
		}
	}
}

int main(){
	int n;
	printf("皇后问题(n<20)n=");
	scanf("%d",&n);
	if(n>20)
		printf("n值太大不能求解");
	else{
		printf("%d皇后问题求解如下：\n",n);
		queen(1,n); // 放置1~n个皇后 
	}

}
