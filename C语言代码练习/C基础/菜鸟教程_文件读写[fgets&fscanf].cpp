#include<stdio.h>

int main(){
	FILE *fp = NULL;
	char buff[255];
	
	fp = fopen("tmp/test.txt","r+");
	fscanf(fp,"%s",buff);
	printf("1:%s\n",buff);
	
	fgets(buff,255,fp);
	// fgetc(); 函数从fp所指向的输入文件中读取一个字符 返回值是读取的字符
	// 如果发生错误返回EOF。
	
	// fgets(); 函数从fp所指向的输入流中读取n-1个字符。它会把读取的字符串复制到
	// 缓冲区buf,并在最后追加一个null字符来中止字符串 
	
	
	printf("2:%s\n",buff);
	// buff指针数组 指针数组 
	
	
	fgets(buff,255,fp);
	printf("3:%s\n",buff);
	fclose(fp);
} 
