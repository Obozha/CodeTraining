#include<stdio.h>

int main(){
	/* 带有5个元素的整形数组 */
	double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
	double *p;
	int i;
	
	p = balance;
	/* 输出数组中每个元素的值 */
	printf("使用指针的数组值\n");
	for(i=0;i<5;i++)
		printf("*(p + %d):%f\n",i,*(p+i));
	
	printf("使用balance作为地址的数组值\n");
	for(i=0;i<5;i++){
		printf("*(balance + %d):%f\n",i,*(balance+i));
	}
	return 0;
}
