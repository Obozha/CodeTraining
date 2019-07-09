#include<stdio.h>

// stdout stdin stderr 的中文名字分别是标准输出 标准输入 标准错误

int main(){
	fprintf(stdout,"Hello");
	fprintf(stderr,"World！");
	return 0;
} 


// stdout(标准输出) 输出方式是行缓冲。输出的字符会先存放缓冲区，等按下回车键
// 时才进行实际的I/O操作 

// stderr(标准出错) 是不带缓冲的，这使得出错信息可以直接尽快地显示出来。

//  关于缓冲的说明:

// 满缓冲 I/O操作只有缓冲区被填满之后才会进行 1.缓冲区满 2.刷出数据(fflush) 3.关闭文件(fclose)
// 行缓冲 通常只有遇到换行符时，才会执行实际的I/O操作;但缓冲区满也会强制执行 1.遇到换行符 2.缓冲区满 3.刷出数据(fflush)4.关闭文件
// 无缓冲 不缓存，直接进行I/O操作 直接输出 
