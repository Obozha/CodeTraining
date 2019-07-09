#include<stdio.h>
#include<string.h>

union Data{
	int i;
	float f;
	char str[20];
};

/*
在这里，可以看到共同体i和f成员有损坏
因为最后 赋给变量的值占用了内存位置
这也是str成员能够完好输出的原因 
*/

int main(){
	union Data data;
	data.i=10;
	data.f=220.5;
	strcpy(data.str,"C programming");
	
	printf("data.i:%d\n",data.i);
	printf("data.f:%f\n",data.f);
	printf("data.str:%s\n",data.str);
	return 0;
}
