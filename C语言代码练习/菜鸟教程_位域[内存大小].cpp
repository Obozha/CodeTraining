#include<stdio.h>
#include<string.h>

/* 定义简单的结构 */

struct{
	unsigned int widthVaildated;
	unsigned int heightValidated;
} status1;

/* 定义位域结构 */
struct{
	unsigned int widthVaildated:1;
	unsigned int heightVaildated:1;
} status2;

int main(){
	printf("Memory size occupied by status1:%d\n",sizeof(status1));
	printf("Memory size occupued by status2:%d\n",sizeof(status2));
	
	return 0;
}


