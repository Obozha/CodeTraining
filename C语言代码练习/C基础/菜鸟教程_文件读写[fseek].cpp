#include<stdio.h>

int main(){
//	FILE *fp = NULL;
//	fp = fopen("tmp/test.txt","r+");
//	fprintf(fp,"This is testing for fprintf...\n");
//	fseek(fp,5,SEEK_SET);
//	if(fputc(65,fp)==EOF){
//		printf("fputc fail");
//	} 
//	fclose(fp);

	printf("%c",65);
	
	FILE *fp;
	fp = fopen("tmp/file.txt","w+");
	fputs("This is runoob.com",fp);
	
	fseek(fp,7,SEEK_SET);
	fputs("C programming Langauge",fp);
	fclose(fp); 
	
	return 0;
} 

// SEEK_SET 0 文件头 
// SEEK_CUR 1 当前点 
// SEEK_END 2 文件尾计算偏移量offset 

// 指向开头，要指到多少个字节，只要控制偏移量。
// fseek(fp,1,SEEK_CUR); 相对当前位置往后移动一个字节
// fseek(fp,-1,SEEK_CUR); 相对当前位置往前移动一个字节 
