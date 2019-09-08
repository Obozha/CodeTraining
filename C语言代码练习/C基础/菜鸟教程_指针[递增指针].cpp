#include<stdio.h>
const int MAX = 3;
int main(){
	int var[] = {10,100,200};
	int i,*ptr;
	
	/* 指针中的数组地址 */
	ptr = var;
	
	for(i=0;i<MAX;i++){
		printf("储存地址：var[%d]=%x\n",i,ptr);
		printf("储存值：var[%d]=%d\n",i,*ptr);
		ptr++;
	}
	return 0;
}
