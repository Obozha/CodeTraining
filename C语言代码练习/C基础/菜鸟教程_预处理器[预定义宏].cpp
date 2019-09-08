#include<stdio.h>

int main(){
	printf("File:%s\n",__FILE__); // 包含当前文件名，一个字符串常量 
	printf("Date:%s\n",__DATE__); 
	printf("Time:%s\n",__TIME__); // 当前时间，一个以HH:MM:SS 格式表示的字符常量  
	printf("Line:%d\n",__LINE__); // 当前行数 
	printf("ANSI:%d\n",__STDC__); // 当编译器以ANSI标准编译时 定义为1 
} 
