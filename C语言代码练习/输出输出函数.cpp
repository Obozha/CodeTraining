#include<stdio.h>
#include<stdlib.h>
/**
%d int 
%ld long int
%hd short int
%c char
%f float
%lf double
%u 无符号
%x 十六进制输出int或者long int或者short int
%o 八进制输出
%s 字符串 
**/
main(){
	int i = -3;
	long int li = 111;
	short int si = 111;
	char c = 'a';
	float f = 3.14;
	double d = 3.14;
	char s[] = "Hello World!";
	
	printf("%d\n",i);
	printf("%ld\n",li);
	printf("%hd\n",si);
	printf("%c\n",c);
	printf("%f\n",f);
	printf("%lf\n",d);
	printf("%u\n",i);
	printf("%#x\n",li); // #添加0x 
	printf("%#o\n",li);   // #添加的0 
	printf("%s\n",s);
	
	system("pause");
	return 0;
}

