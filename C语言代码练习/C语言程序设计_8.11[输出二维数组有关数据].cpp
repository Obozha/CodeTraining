#include<stdio.h>
int main() {
	int a[3][4] = {1,3,5,7,9,11,13,15,17,19,21,23};
	printf("%d,%d\n",a,*a);					// 6422224 0行起始地址,6422224 0行0列元素地址 
	printf("%d,%d\n",a[0],*(a+0));			// 6422224 6422224 0行0列地址 
	printf("%d,%d\n",&a[0],&a[0][0]);		// 6422224 0行起始地址 6422224 0行0列地址 
	printf("%d,%d\n",a[1],a+1);				// 6422240(6422224+16) 1行0列地址 ,6422240 1行起始地址 
	printf("%d,%d\n",&a[1][0],*(a+1)+0);	// 6422240 1行0列地址 6422240 1行0列地址 
	printf("%d,%d\n",a[2],*(a+2));			// 6422256,6422256 2行0列地址 
	printf("%d,%d\n",&a[2],a+2);			// 6422256,6422256 2行0列地址 
	printf("%d,%d\n",a[1][0],*(*(a+1)+0));  // 9,9 1行0列地址 
	printf("%d,%d\n",*a[2],*(*(a+2)+0));	// 17,17 2行0列地址 
	return 0;
}
