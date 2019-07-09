#include<stdio.h>

int main(){
	int test1,test2;
	
	FILE *fp = NULL;
	fp = fopen("G:/code/tmp/test.txt","w+");
	test1 = fprintf(fp,"This is testing for fprint...\n");
	printf("%d",test1);
	
	test2 = fputs("This is testing for fputs...\n",fp);
	// 函数fputs()把字符串s写入到fp所指向的输出流中。如果写入成功，它会返回一个非负值
	// 如果发生错误 则会返回EOF  
	
	printf("%d",test2);
		

	fclose(fp);
	
}
