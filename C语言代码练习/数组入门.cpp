#include<stdio.h>
#include<stdlib.h>

main(){
	
	printf("char类型所占的内存大小%d\n",sizeof(char));
	
	char arr[]= "Hello"; 
	int i[] = {1,2,3,4,5};
	
	printf("----------------------------------------\n");
	printf("输出字符数组\n");
	printf("arr[0]%c\n",arr[0]);
	printf("arr[1]%c\n",arr[1]);
	printf("arr[2]%c\n",arr[2]);
	printf("arr[3]%c\n",arr[3]);
	printf("arr[4]%c\n",arr[4]);
	printf("----------------------------------------\n");
	printf("输出字符数组在内存中的地址\n");
	printf("arr[0]%#x\n",&arr[0]);
	printf("arr[1]%#x\n",&arr[1]);
	printf("arr[2]%#x\n",&arr[2]);
	printf("arr[3]%#x\n",&arr[3]);
	printf("arr[4]%#x\n",&arr[4]);
	printf("arr%#x\n",&arr);
	// 每增加一个下标，地址向后增加一个单位
	// arr可以不使用&照样取出内存地址，和数组的第一个下标的内存地址一样 
	printf("----------------------------------------\n");
	printf("用指针输出字符数组的内存地址\n");
	char * p = &arr[0];
	printf("arr[0]%c\n",*p);
	printf("arr[1]%c\n",*(p+1));
	printf("arr[2]%c\n",*(p+2));
	printf("arr[3]%c\n",*(p+3));
	printf("arr[4]%c\n",*(p+4));
	
	printf("----------------------------------------\n");
	printf("输出整形数组\n");
	printf("i[0]%d\n",i[0]);
	printf("i[0]%d\n",i[1]);
	printf("i[0]%d\n",i[2]);
	printf("i[0]%d\n",i[3]);
	printf("i[0]%d\n",i[4]);
	printf("----------------------------------------\n");
	printf("输出整形数组在内存中的地址\n");
	printf("i[0]%#x\n",&i[0]);
	printf("i[0]%#x\n",&i[1]);
	printf("i[0]%#x\n",&i[2]);
	printf("i[0]%#x\n",&i[3]);
	printf("i[0]%#x\n",&i[4]);
	// 因为是4个字节所以在内存中每个下标，移动4个值 
	printf("----------------------------------------\n");
	printf("用指针输出整形数组在内存中的地址\n");
	int * pi;
	pi = &i[0];
	printf("i[0]%d\n",*pi);
	printf("i[0]%d\n",*(pi+1));
	printf("i[0]%d\n",*(pi+2));
	printf("i[0]%d\n",*(pi+3));
	printf("i[0]%d\n",*(pi+4));
	// 虽然每个下标的内存地址相差4个值，但是指针加减是对单位的加减，而且是连续的内存地址才能相加减 
	printf("----------------------------------------\n");
	printf("指针加减%d",(pi+2)-pi);
}
