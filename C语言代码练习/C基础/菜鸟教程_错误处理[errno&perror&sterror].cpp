#include<stdio.h>
#include<errno.h>
#include<string.h>

extern int errno;

// 您应该使用 stderr 文件流来输出所有的错误。 
int main(){
	FILE *pf;
	int errnum;
	pf = fopen("unexit.txt","rb");
	if(pf == NULL){
		errnum = errno;
		fprintf(stderr,"错误号:%d\n",errno);
		perror("通过perror输出错误");
		fprintf(stderr,"打开文件错误:%s\n",strerror(errnum)); 
	}else{
		fclose(pf);
	}
	return 0;
} 

// c语言提供了perror()和strerror()函数来显示与errno相关的文本信息

// perror()函数显示您传给它的字符串 后跟一个冒号、一个空格和当前errno值的文本的表示形式。
// strerror() 函数，返回一个指针，指针指向当前errno值的文本表示形式 
