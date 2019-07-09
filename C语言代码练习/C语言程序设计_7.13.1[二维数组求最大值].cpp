#include<stdio.h>

int max_value(int array[][4]);

int main(){
	
	int a[3][4] = {{1,3,5,7},{2,4,6,8},{15,17,34,12}};
	printf("Max value is %d\n",max_value(a));
	return 0;
}

// 如果对全部元素都赋初值 即提供全部数据 则定义数组对维可以不指定，但第二维度的长度不能省略 
int max_value(int array[][4]){
	 
	 printf("sizeof(array):%d\n",sizeof(array));
	 printf("sizeof(array[0][0]):%d\n",sizeof(array[0][0]));
	 
	 int i,j,max,x,y;
	 max=array[0][0];
	 
	 for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			if(array[i][j]>max){
				max=array[i][j];; // 把最大值放在max
				x=i;
				y=j;
			}
	printf("Max位置为:行:%d,列:%d\n",x+1,y+1);
	return max;
}
